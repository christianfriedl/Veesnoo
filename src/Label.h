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
    Label(const std::string& text, const int x, const int y);

    static std::shared_ptr<Label> create(const std::string& text, const int x, const int y) {
        return std::make_shared<Label>(text, x, y);
    }

    void setText(const std::string& text);
    /*
    Label(Label&& other);
    Label& operator=(Label&& other);
    */
    virtual void addContent() override;
private:
    std::string text_;
};

}

#endif
