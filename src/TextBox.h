#ifndef NV_TEXT_BOX_H
#define NV_TEXT_BOX_H

#include <string>
#include "FocusableWidget.h"
#include "ChangeEvent.h"

namespace nv {
    

class TextBox : public FocusableWidget {
public:
    typedef enum { Mode_normal, Mode_insert, Mode_replace } Mode;

    TextBox(const int x, const int y, const int width);
    virtual bool receiveKey(const int ch) override;
    virtual void refresh() override;
    const std::string& getText();
    void setText(const std::string& text) { text_ = text; }
    inline int getCursorPos();

    bool cursorTo(int x);
    bool cursorRight();
    bool cursorLeft();
    bool cursorToStart();
    bool cursorToEnd();

    Mode getMode() { return mode_; }
    void setMode(Mode mode) { mode_ = mode; }

    sigc::signal<void, const std::shared_ptr<ChangeEvent>&> onAfterChange;

private:
    char fillCharForMode(Mode mode);
    std::string text_;
    Mode mode_;
    unsigned long cursorX_;
    unsigned long startX_;

};

}

#endif
