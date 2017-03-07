#include "FocusableContainer.h"

namespace nv {
    class Screen: public FocusableContainer {
        public:
            Screen();
            static std::shared_ptr<Screen> create();
            bool receiveKey(int ch);
    };
}
