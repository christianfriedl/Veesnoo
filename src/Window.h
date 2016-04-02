#ifndef NV_WINDOW_H
#define NV_WINDOW_H

#include "FocusableContainer.h"

namespace nv {

class Window : public FocusableContainer {
public:
    Window(const Rect& rect, const std::string title = "");
    virtual void refresh();
    void setTitle(const std::string title);
    void resize(const int width, const int height);

protected:
    virtual void calculateContentRect();

private:
    std::string title_;
};

}

#endif