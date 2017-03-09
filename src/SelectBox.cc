#include "TextBox.h"
#include <stdio.h>


namespace nv {

    TextBox::TextBox(const int x, const int y, const int width) : FocusableWidget(Rect(x, y, width, 1)),
            status_(Status_normal), cursorX_(0), startX_(0) {}

    const std::string& TextBox::getText() { return text_; }

    void
    TextBox::refresh() {
        addString(text_, 0, 0);
        int cur = (cursorX_ > rect->getWidth() - 1) ? (rect->getWidth() - 1) : cursorX_;

        cursesWindow_->setCursorPosition(cur, 0);
        FocusableWidget::refresh();
    }

    bool
    TextBox::receiveKey(const int ch) {
        bool received = false;
        if ( status_ == Status_normal ) {
            switch ( ch ) {
                case KEY_IL:
                case 'i':
                    status_ = Status_insert;
                    received = true;
                    break;
                case KEY_DL:
                case 'x':
                    text_.replace(cursorX_, 1, "");
                    received = true;
                    break;
            }
        } else if ( status_ == Status_insert ) {
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
                        status_ = Status_normal;
                        received = true;
                        break;
                }
            }
        } else if ( status_ == Status_replace ) {
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
                        status_ = Status_normal;
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
        return true;
    }

    bool TextBox::cursorLeft() { 
        if ( cursorX_ == 0 )
            return false;
        --cursorX_;
        return true;
    }

    bool TextBox::cursorTo(int x) {
        if ( x > text_.size() )
            return false;
        cursorX_ = x;
        return true;
    }
}
