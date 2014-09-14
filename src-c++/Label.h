#ifndef NV_LABEL_H
#define NV_LABEL_H

#include <string>
#include <iostream>
#include "Rect.h"
#include "CursesWindow.h"
#include "Widget.h"

namespace nv {

class Label: public Widget {
public:
    Label(const std::string& text, const int x, const int y): Widget(Rect(x, y, text.size(), 1)), text_(text) { }
    virtual void refresh();
private:
    std::string text_;
};

}

#endif
