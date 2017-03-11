#ifndef NV_CONFIRM_BOX_H
#define NV_CONFIRM_BOX_H

#include "Window.h"
#include "Label.h"
#include "Button.h"
#include "BasicEvent.h"
#include "FocusStealer.h"

namespace nv {

    class ConfirmBox: public Window, public FocusStealer {
        public:
            ConfirmBox(const std::string& title, const std::string& text);
            virtual ~ConfirmBox();
            static const std::shared_ptr<ConfirmBox> create(const std::string& title, const std::string& text);
            const std::shared_ptr<Label> getLabel();
            void layout();
            virtual bool close();
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterClose;

        private:
            std::shared_ptr<Label> label_;
            std::shared_ptr<Button> okButton_;
            std::shared_ptr<Button> cancelButton_;
            std::string title_;
    };

}

#endif
