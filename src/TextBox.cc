#include "TextBox.h"
#include <stdio.h>
#include <string.h>


namespace nv {

    TextBox::TextBox(const int x, const int y, const int width) : FocusableWidget(Rect(x, y, width, 1)),
            mode_(Mode_normal), cursorX_(0), startX_(0) {}

    const std::string& TextBox::getText() { return text_; }

    inline int TextBox::getCursorPos() {
        return cursorX_ - startX_;
    }

    inline char TextBox::fillCharForMode(Mode mode) {
        if ( mode == Mode_insert || mode == Mode_replace ) 
            return ' ';
        else
            return '.';
    }

    void
    TextBox::refresh() {
        char fillChar = fillCharForMode(mode_);
        if ( isFocused() ) {
            cursesWindow_->attrOn(A_REVERSE);
        }
        LOG("fillchar is '%c'", fillChar);

        addString(text_.substr(startX_), 0, 0);
        Logger::get().log("text is %s", text_.c_str());

        for ( int i = std::min(rect_.getWidth(), (int)text_.length() - startX_); i < rect_.getWidth(); ++i )
            addCh(fillChar, i, 0);

        int cur = (getCursorPos() > rect_.getWidth() - 1) ? (rect_.getWidth() - 1) : getCursorPos();
        if ( isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
        cursesWindow_->setCursorPosition(cur, 0);
        FocusableWidget::refresh();
    }

    bool
    TextBox::receiveKey(const int ch) {
        LOG("TextBox::receiveKey '%c' (%i) '%s', isprint: %i, iswprint: %i, mode: %i", ch, ch, keyname(ch), isprint(ch), iswprint(ch), mode_); // should not leak...
        bool received = false;
        if ( mode_ == Mode_normal ) { // normal mode
            switch ( ch ) {
                case KEY_IL: // go to insert mode
                case 'i':
                    mode_ = Mode_insert;
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
        } else if ( mode_ == Mode_insert ) {
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
                    case KEY_BACKSPACE: // backspace
                        if ( cursorLeft() )
                            text_.replace(cursorX_, 1, "");
                        received = true;
                        break;
                    case Key_Esc:
                        {
                            mode_ = Mode_normal;
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
        } else if ( mode_ == Mode_replace ) { // TODO this is quite unfinished
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
                        mode_ = Mode_normal;
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
        if ( cursorX_ > rect_.getWidth() )
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
        if ( x > text_.size() )
            return false;
        cursorX_ = x;
        if ( cursorX_ > rect_.getWidth() )
            startX_ = cursorX_ - rect_.getWidth();
        return true;
    }

    bool TextBox::cursorToStart() {
        return cursorTo(0);
    }

    bool TextBox::cursorToEnd() {
        return cursorTo(text_.length());
    }

}
