#ifndef NV_VERTICAL_MENU_H
#define NV_VERTICAL_MENU_H

#include "Window.h"
#include "Label.h"
#include "BasicEvent.h"

namespace nv {

    class MessageBox: public Window {
        public:
            MessageBox(const std::string& title, const std::string& text);
            virtual ~MessageBox();
            static const std::shared_ptr<MessageBox> create(const std::string& title, const std::string& text);
            const std::shared_ptr<Label> getLabel();
            void layout();
            virtual bool receiveKey(int ch);
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterClose;

        private:
            std::shared_ptr<Label> label_;
            std::string title_;
    };

}

#endif
