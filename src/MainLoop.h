#include <memory>
#include "FocusableContainer.h"

namespace nv {

    class MainLoop {
        public:
            explicit MainLoop(std::shared_ptr<FocusableContainer> mainContainer);
            MainLoop(const MainLoop&) = delete;
            MainLoop& operator=(const MainLoop&) = delete;
            std::shared_ptr<FocusableContainer>& getContainer();

            void run();

        private:
            std::shared_ptr<FocusableContainer> mainContainer_;
    };

}
