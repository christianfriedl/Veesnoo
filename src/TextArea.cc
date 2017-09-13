#include "Logger.h"
#include "TextArea.h"
#include <stdio.h>
#include <string.h>


namespace nv {

    TextArea::TextArea(const Rect& rect) : FocusableWidget(rect),
            mode_(TextAreaMode::normal), cursorPos_(0) {}

    const std::string& TextArea::getText() { return text_; }

    void TextArea::focus() {
        mode_ = TextAreaMode::insert;
        FocusableWidget::focus();
    }


    inline char TextArea::fillCharForMode(TextAreaMode mode) {
        if ( mode == TextAreaMode::insert || mode == TextAreaMode::replace ) 
            return ' ';
        else
            return '.';
    }

    Point TextArea::pointFromPosition(const int pos) const {
        return Point(pos % getRect().getWidth(), pos / getRect().getWidth());
    }

    int TextArea::pointToPosition(const Point p) const {
        return p.getX() + getRect().getWidth() * p.getY();
    }

    void TextArea::refresh() {
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        char fillChar = fillCharForMode(mode_);
        if ( isFocused() ) {
            cursesWindow_->attrOn(A_REVERSE);
        }
        unsigned i = 0; 
        int y = 0;
        const int width = getRect().getWidth();
        const int height = getRect().getHeight();
        for ( ; i < text_.size() && y < height; i += width, ++y ) {
            LOGMETHOD("i %i y %i", i, y);
            const std::string text = text_.substr(i, width);
            const std::string fillText = std::string(width - text.size(), fillChar);
            addString(text + fillText, 0, y);
        }
        for ( ; y < height; ++y ) {
            std::string text = std::string(width, fillChar);
            addString(text, 0, y);
        }

        /*
        for ( int i = std::min((unsigned long)rect_.getWidth(), text_.length() - startX_); i < rect_.getWidth(); ++i )
            addCh(fillChar, i, 0);
            */

        if ( isFocused() )
            cursesWindow_->attrOff(A_REVERSE);
        Point point = pointFromPosition(cursorPos_);
        cursesWindow_->setCursorPosition(point.getX(), point.getY());
        FocusableWidget::refresh();
    }

    bool TextArea::receiveKey(const int ch) {
        LOGMETHOD("'%c' (%i) '%s', isprint: %i, iswprint: %i, mode: %i", ch, ch, keyname(ch), isprint(ch), iswprint(ch), mode_); // should not leak...
        bool received = false;
        if ( mode_ == TextAreaMode::normal ) { // normal mode
            switch ( ch ) {
                case KEY_IL: // go to insert mode
                case 'i':
                    mode_ = TextAreaMode::insert;
                    received = true;
                    break;
                case KEY_DL: // delete char under cursor
                case 'x':
                    text_.replace(cursorPos_, 1, "");
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
                case KEY_UP:
                case 'k':
                    cursorUp();
                    received = true;
                    break;
                case KEY_DOWN:
                case 'j':
                    cursorDown();
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
        } else if ( mode_ == TextAreaMode::insert ) {
            if ( isprint(ch) ) { // TODO this prolly won't work with full utf-8 support
                if ( (unsigned long)cursorPos_ <= text_.size() ) {
                    text_.insert(cursorPos_, 1, ch);
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
                    case KEY_UP:
                        cursorUp();
                        received = true;
                        break;
                    case KEY_DOWN:
                        cursorDown();
                        received = true;
                        break;
                    case KEY_BACKSPACE: // backspace
                        if ( cursorLeft() )
                            text_.replace(cursorPos_, 1, "");
                        received = true;
                        break;
                    case Key_Esc:
                        {
                            mode_ = TextAreaMode::normal;
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
        } else if ( mode_ == TextAreaMode::replace ) { // TODO this is quite unfinished
            if ( iswprint(ch) ) {
                if ( (unsigned long)cursorPos_ <= text_.size() ) {
                    char s[2];
                    sprintf(s, "%c", ch);
                    text_.replace(cursorPos_, 1, s);
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
                    case KEY_UP:
                        cursorUp();
                        received = true;
                        break;
                    case KEY_DOWN:
                        cursorDown();
                        received = true;
                        break;
                    case Key_Esc:
                        mode_ = TextAreaMode::normal;
                        received = true;
                        break;
                }
            }
        } else
            throw Exception("no such status");
        return received;
    }

    bool TextArea::cursorRight() { 
        if ((unsigned long)cursorPos_ == text_.size())
            return false;
        ++cursorPos_;
        return true;
    }

    bool TextArea::cursorLeft() { 
        if ( cursorPos_ == 0 )
            return false;
        --cursorPos_;
        return true;
    }

    bool TextArea::cursorUp() { 
        Point point(pointFromPosition(cursorPos_));
        if ( point.getY() == 0 )
            return false;
        Point point2(point.getX(), point.getY() - 1);
        cursorTo(pointToPosition(point2));
        return true;
    }

    bool TextArea::cursorDown() { 
        Point point(pointFromPosition(cursorPos_));
        if ( point.getY() == rect_.getHeight() - 1 )
            return false;
        Point point2(point.getX(), point.getY() + 1);
        cursorTo(pointToPosition(point2));
        return true;
    }

    bool TextArea::cursorTo(const int pos) {
        if ( (unsigned long)pos > text_.size() )
            return false;
        cursorPos_ = pos;
        return true;
    }

    bool TextArea::cursorToStart() {
        return cursorTo(0);
    }

    bool TextArea::cursorToEnd() {
        return cursorTo(text_.length());
    }

}
