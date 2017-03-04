#include "Logger.h"
#include "ContainerFocusManager.h"
#include "Widget.h"
#include "Window.h"

namespace nv {

    Window::Window(const Rect& rect, const std::string title) : FocusableContainer(rect), title_(title) {
        contentRect = Rect(1, 1, rect.getWidth() - 2, rect.getHeight() - 2);
        Logger::get().log("new Window @ %ld %s", toString().c_str());
    }

    void 
    Window::refresh() {
        setCWPosition(); // not necessary until we have a working move(), but what the bloody heck
        cw->addBorder();
        cw->addString(title_, ( rect.getWidth() - title_.size() ) / 2, 0);
        FocusableContainer::refresh();
    }


}
