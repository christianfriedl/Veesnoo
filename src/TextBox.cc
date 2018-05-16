/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#include "Logger.h"
#include "TextBox.h"
#include "ColorSet.h"
#include <stdio.h>
#include <string.h>


namespace veesnoo {

    TextBox::TextBox(const int x, const int y, const int width) : FocusableWidget(Rect(x, y, width, 1)),
            mode_(TextBoxMode::normal), cursorX_(0), startX_(0) 
    {
        contentFocusedColorAttribute_ = ColorSet::getColorAttribute(WidgetClass::TEXTBOX, ColorClass::CONTENT_FOCUSED);
        contentEditColorAttribute_ = ColorSet::getColorAttribute(WidgetClass::TEXTBOX, ColorClass::CONTENT_EDIT);
    }

    std::shared_ptr<TextBox> TextBox::create(const int x, const int y, const int width) {
        LOGSTATICMETHOD("TextBox::create(%i, %i, %i)", x, y, width);
        return std::make_shared<TextBox>(x, y, width);
    }


    const std::string& TextBox::getText() { return text_; }

    inline int TextBox::getCursorPos() {
        return cursorX_ - startX_;
    }

    inline char TextBox::fillCharForMode(TextBoxMode mode) {
        if ( mode == TextBoxMode::insert || mode == TextBoxMode::replace ) 
            return ' ';
        else
            return '.';
    }

    void TextBox::focus() {
        mode_ = TextBoxMode::insert;
        FocusableWidget::focus();
    }

    std::shared_ptr<ColorAttribute> TextBox::getContentColorAttribute() {
        if ( isFocused() && ( mode_ == TextBoxMode::insert || mode_ == TextBoxMode::replace ) )
            return contentEditColorAttribute_;
        else
            return FocusableWidget::getContentColorAttribute(isFocused());
    }


    void TextBox::addContent() {
        LOGMETHODONLY();
        char fillChar = fillCharForMode(mode_);
        startColorAttribute(getContentColorAttribute());
        LOGMETHOD("fillchar is '%c'", fillChar);

        addString(text_.substr(startX_), 0, 0);
        LOGMETHOD("text is %s", text_.c_str());

        for ( int i = std::min((unsigned long)rect_.getWidth(), text_.length() - startX_); i < rect_.getWidth(); ++i )
            addCh(fillChar, i, 0);

        int cur = (getCursorPos() > rect_.getWidth() - 1) ? (rect_.getWidth() - 1) : getCursorPos();
        endColorAttribute(getContentColorAttribute());
        cursesWindow_->setCursorPosition(cur, 0);
    }

    bool TextBox::receiveKey(const int ch) {
        LOGMETHOD("'%c' (%i) '%s', isprint: %i, iswprint: %i, mode: %i", ch, ch, keyname(ch), isprint(ch), iswprint(ch), mode_); // should not leak...
        bool received = false;
        if ( mode_ == TextBoxMode::normal ) { // normal mode
            switch ( ch ) {
                case KEY_IL: // go to insert mode
                case 'i':
                    mode_ = TextBoxMode::insert;
                    received = true;
                    break;
                case KEY_DL: // delete char under cursor
                case 'x':
                    text_.replace(cursorX_, 1, "");
                    received = true;
                    break;
                case 'h': // move left
                case KEY_BACKSPACE: // backspace
                case KEY_LEFT:
                    cursorLeft();
                    received = true;
                    break;
                case 'l': // move right
                case KEY_RIGHT:
                    cursorRight();
                    received = true;
                    break;
                case '0': // move to start
                case KEY_HOME:
                    cursorToStart();
                    received = true;
                    break;
                case '$': // move to end
                case KEY_END:
                    cursorToEnd();
                    received = true;
                    break;
                default:
                    auto name = keyname(ch);
                    if  ( strncmp(name, "^A", 2) == 0 ) {
                        cursorToStart();
                        received = true;
                    } else if  ( strncmp(name, "^E", 2) == 0 ) {
                        cursorToEnd();
                        received = true;
                    }
                    break;
            }
        } else if ( mode_ == TextBoxMode::insert ) {
            if ( isprint(ch) ) { // TODO this prolly won't work with full utf-8 support
                if ( cursorX_ <= text_.size() ) {
                    text_.insert(cursorX_, 1, ch);
                    cursorRight();
                }
                received = true;
            } else {
                switch ( ch ) {
                    case KEY_RIGHT:
                        cursorRight();
                        received = true;
                        break;
                    case KEY_LEFT:
                        cursorLeft();
                        received = true;
                        break;
                    case KEY_DOWN:
                    case KEY_UP:
                        {
                            mode_ = TextBoxMode::normal;
                            auto ev(std::make_shared<ChangeEvent>(shared_from_this()));
                            onAfterChange.emit(ev);
                            received = false;
                        }
                        break;
                    case KEY_BACKSPACE: // backspace
                        if ( cursorLeft() )
                            text_.replace(cursorX_, 1, "");
                        received = true;
                        break;
                    case Key_Esc:
                        {
                            mode_ = TextBoxMode::normal;
                            auto ev(std::make_shared<ChangeEvent>(shared_from_this()));
                            onAfterChange.emit(ev);
                            received = true;
                        }
                        break;
                    default:
                        auto name = keyname(ch);
                        if  ( strncmp(name, "^A", 2) == 0 ) {
                            cursorToStart();
                            received = true;
                        } else if  ( strncmp(name, "^E", 2) == 0 ) {
                            cursorToEnd();
                            received = true;
                        }
                        break;
                }
            }
        } else if ( mode_ == TextBoxMode::replace ) { // TODO this is quite unfinished
            if ( iswprint(ch) ) {
                if ( cursorX_ <= text_.size() ) {
                    char s[2];
                    sprintf(s, "%c", ch);
                    text_.replace(cursorX_, 1, s);
                    cursorRight();
                }
                received = true;
            } else {
                switch ( ch ) {
                    case KEY_RIGHT:
                        cursorRight();
                        received = true;
                        break;
                    case KEY_LEFT:
                        cursorLeft();
                        received = true;
                        break;
                    case Key_Esc:
                        mode_ = TextBoxMode::normal;
                        received = true;
                        break;
                }
            }
        } else
            throw Exception("no such status");
        return received;
    }

    bool TextBox::cursorRight() { 
        if (cursorX_ == text_.size())
            return false;
        ++cursorX_;
        if ( cursorX_ > (unsigned long)rect_.getWidth() )
            ++startX_;
        return true;
    }

    bool TextBox::cursorLeft() { 
        if ( cursorX_ == 0 )
            return false;
        --cursorX_;
        if ( cursorX_ < startX_ )
            --startX_;
        return true;
    }

    bool TextBox::cursorTo(int x) {
        if ( (unsigned long)x > text_.size() )
            return false;
        cursorX_ = x;
        if ( cursorX_ > (unsigned long)rect_.getWidth() )
            startX_ = cursorX_ - (unsigned long)rect_.getWidth();
        return true;
    }

    bool TextBox::cursorToStart() {
        return cursorTo(0);
    }

    bool TextBox::cursorToEnd() {
        return cursorTo(text_.length());
    }

}
