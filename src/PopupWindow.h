#ifndef NV_FOCUS_STEALER_H
#define NV_FOCUS_STEALER_H

#include "Window.h"
#include "FocusStealing.h"

class Focusable;
namespace nv {
    /**
     * we derive from Window because all stealers will be windows
     */

    class PopupWindow: public Window, public FocusStealing {
        public:
        explicit PopupWindow(const Rect& rect, const std::string title = "");
        static std::shared_ptr<PopupWindow> create(const Rect& rect, const std::string title = "") { return std::make_shared<PopupWindow>(rect, title); }
            virtual ~PopupWindow();
            virtual bool open() override;
            virtual bool close() override;
            virtual const std::shared_ptr<Focusable>& getPreviouslyFocusedWidget() const override;
            virtual void refresh() override { LOGMETHODONLY(); Window::refresh(); } // just for debug
            virtual bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return Window::receiveKey(ch); } // just for debug
        private:
            std::shared_ptr<Focusable> previouslyFocusedWidget_;
    };
}

#endif
