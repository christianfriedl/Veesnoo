#include "TextBox.h"
#include <stdio.h>


namespace nv {

    TextBox::TextBox(const int x, const int y, const int width) : FocusableWidget(Rect(x, y, width, 1)),
            mode_(Mode_normal), cursorX_(0), startX_(0) {}

    const std::string& TextBox::getText() { return text_; }

    inline int TextBox::getCursorPos() {
        return cursorX_ - startX_;
    }

    void
    TextBox::refresh() {
        char fillChar = '.';
        if ( isFocused() ) {
            Logger::get().log("is focused! ");
            cw->attrOn(A_REVERSE);
            fillChar = ' ';
        }
        LOG("fillchar is '%c'", fillChar);

        addString(text_.substr(startX_), 0, 0);
        Logger::get().log("text is %s", text_.c_str());

        for ( int i = std::min(rect.getWidth(), (int)text_.length() - startX_); i < rect.getWidth(); ++i )
            addCh(fillChar, i, 0);

        int cur = (getCursorPos() > rect.getWidth() - 1) ? (rect.getWidth() - 1) : getCursorPos();
        cw->setCursorPosition(cur, 0);
        FocusableWidget::refresh();
        if ( isFocused() )
            cw->attrOff(A_REVERSE);
    }

    bool
    TextBox::receiveKey(const int ch) {
        LOG("TextBox receiveKey '%c' (%i)", ch, ch);
        LOG("TextBox receiveKey mode is %i", mode_);
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
                case KEY_BACKSPACE: // backspace
                    if ( cursorLeft() )
                        text_.replace(cursorX_, 1, "");
                    received = true;
                    break;
                case 'h': // move left
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
            }
        } else if ( mode_ == Mode_insert ) {
            if ( iswprint(ch) ) {
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
                    case Key_Esc:
                        mode_ = Mode_normal;
                        received = true;
                        break;
                }
            }
        } else if ( mode_ == Mode_replace ) {
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
        if ( cursorX_ > rect.getWidth() )
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
        if ( cursorX_ > rect.getWidth() )
            startX_ = cursorX_ - rect.getWidth();
        return true;
    }

    bool TextBox::cursorToStart() {
        return cursorTo(0);
    }

    bool TextBox::cursorToEnd() {
        return cursorTo(text_.length());
    }

}
