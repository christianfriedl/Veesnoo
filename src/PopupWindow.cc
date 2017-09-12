#include "Logger.h"
#include "PopupWindow.h"

namespace nv {

    PopupWindow::PopupWindow(const Rect& rect, const std::string title): Window(rect, title), FocusStealing() {
        LOGMETHODONLY();
    }

    PopupWindow::~PopupWindow() {
        LOGMETHODONLY();
    }

    const std::shared_ptr<Focusable>& PopupWindow::getPreviouslyFocusedWidget() const {
        return previouslyFocusedWidget_;
    }

    bool PopupWindow::open() {
        LOGMETHODONLY();
        auto root = findRootFocusable();
        previouslyFocusedWidget_ = root->getFocusedWidget();
        LOGMETHOD("setting previouslyFocusedWidget_ = %llx", previouslyFocusedWidget_.get());
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
        LOGMETHODONLY();
        hide();
        if ( previouslyFocusedWidget_.use_count() == 0 ) {
            Logger::get().log("PopupWindow(%llx)::close(): no previouslyFocusedWidget_ ", this);
            return false;
        }

        Logger::get().log("PopupWindow(%llx)::close(): previouslyFocusedWidget_ = %llx", this, previouslyFocusedWidget_.get());

        blur();

        LOGMETHOD("will call focus() on previouslyFocusedWidget_ = %llx", previouslyFocusedWidget_.get());
        previouslyFocusedWidget_->focus();
        return true;
    }
}
