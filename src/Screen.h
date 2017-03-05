#include "FocusableContainer.h"

namespace nv {
    class Screen: public FocusableContainer {
        public:
            Screen();
            bool receiveKey(int ch);
    };
}
