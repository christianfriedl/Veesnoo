#ifndef NV_TEXT_BOX_H
#define NV_TEXT_BOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {
    

class TextBox : public FocusableWidget {
public:
    typedef enum { Mode_normal, Mode_insert, Mode_replace } Mode;

    TextBox(const int x, const int y, const int width);
    virtual bool receiveKey(const int ch);
    const std::string& getText();
    void setText(const std::string& text) { text_ = text; }
    virtual void refresh();
    inline int getCursorPos();

    bool cursorTo(int x);
    bool cursorRight();
    bool cursorLeft();
    bool cursorToStart();
    bool cursorToEnd();

    Mode getMode() { return mode_; }
    void setMode(Mode mode) { mode_ = mode; }

private:
    char fillCharForMode(Mode mode);
    std::string text_;
    Mode mode_;
    int cursorX_;
    int startX_;

};

}

#endif
