#include "Logger.h"
#include "PopupWindow.h"

namespace nv {

    PopupWindow::PopupWindow(const Rect& rect, const std::string title): Window(rect, title), FocusStealing() {}
    PopupWindow::~PopupWindow() {}

    const std::shared_ptr<Focusable>& PopupWindow::getPreviouslyFocusedWidget() const {
        return previouslyFocusedWidget_;
    }


    bool PopupWindow::open() {
        Logger::get().log("PopupWindow(%llx)::open()", this);
        auto root = findRootFocusable();
        previouslyFocusedWidget_ = root->getFocusedWidget();
        Logger::get().log("PopupWindow(%llx)::open(), previouslyFocusedWidget_ = %lld", previouslyFocusedWidget_.get());
        show();
        focus();
        refresh();
        return true;
    }

    /**
     * we stole the focus on opening, so
     * we need to give it back now
     */
    bool PopupWindow::close() {
        Logger::get().log("PopupWindow(%llx)::close()", this);
        hide();
        if ( previouslyFocusedWidget_.use_count() == 0 ) {
            Logger::get().log("PopupWindow(%llx)::close(): no previouslyFocusedWidget_ ", this);
            return false;
        }

        Logger::get().log("PopupWindow(%llx)::close(): previouslyFocusedWidget_ = %lld", this, previouslyFocusedWidget_.get());

        blur();
        previouslyFocusedWidget_->focus();
        return true;
    }
}
