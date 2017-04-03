#ifndef NV_BUTTON_H
#define NV_BUTTON_H

#include <string>
#include "FocusableWidget.h"
#include "BasicEvent.h"

namespace nv {

    typedef enum { ButtonState_normal, ButtonState_pushed } ButtonState;

    class Button: public FocusableWidget { // , public KeyReceiving {
        public:
            Button(const std::string& text, int x, int y);
            void refresh() override;
            bool push(); 
            virtual bool receiveKey(int ch) override;
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterPush;

        private:
            std::string text_;
            ButtonState state_;

    };

}

#endif
