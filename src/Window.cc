#include "Logger.h"
#include "ContainerFocusManager.h"
#include "Widget.h"
#include "Window.h"

namespace nv {

    Window::Window(const Rect& rect, const std::string title) : FocusableContainer(rect), title_(title) {
        isFocusStealing_ = true;
        contentRect_ = Rect(1, 1, rect.getWidth() - 2, rect.getHeight() - 2);
        Logger::get().log("new Window @ %ld %s", toString().c_str());
    }

    void Window::refresh() {
        LOGMETHODONLY();
        Logger::get().log("Window(%llx)::refresh(), isVisible_=%i", this, isVisible_);
        if ( !getIsVisibleBubbling() )
            return;
        setCWPosition(getAbsoluteRect()); // not necessary until we have a working move(), but what the bloody heck
        cursesWindow_->addBorder();
        cursesWindow_->addString(title_, ( rect_.getWidth() - title_.size() ) / 2, 0);
        FocusableContainer::refresh();
    }


}
