#ifndef NV_WINDOW_H
#define NV_WINDOW_H

#include <memory>
#include "FocusableContainer.h"

namespace nv {

class Window : public FocusableContainer {
public:
    Window(const Rect& rect, const std::string title = "");
    static std::shared_ptr<Window> create(const Rect& rect, const std::string title = "") { return std::make_shared<Window>(rect, title); }
    virtual void refresh() override;
    void setTitle(const std::string title);

private:
    std::string title_;
};

}

#endif
