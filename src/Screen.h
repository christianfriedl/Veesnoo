#include "FocusableContainer.h"

namespace nv {
    class Screen: public FocusableContainer {
        public:
            Screen();
            static std::shared_ptr<Screen> create();
            virtual void refresh() override { LOGMETHODONLY(); FocusableContainer::refresh(); } // just for debug
            bool receiveKey(int ch) override;
    };
}
