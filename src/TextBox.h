#ifndef NV_TEXT_BOX_H
#define NV_TEXT_BOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

class TextBox : public FocusableWidget {
public:
    TextBox(const int x, const int y, const int width);
    virtual bool receiveKey(const int ch);
    const std::string& getText();
    virtual void refresh();

    bool cursorTo(unsigned int x);
    bool cursorRight();
    bool cursorLeft();

    typedef enum { Status_normal, Status_insert, Status_replace } Status;
private:
    std::string text_;
    Status status_;
    unsigned int cursorX_;
    unsigned int startX_;

};

}

#endif