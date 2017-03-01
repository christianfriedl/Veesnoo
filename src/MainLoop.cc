#include "MainLoop.h"

namespace nv {

    MainLoop::MainLoop(std::shared_ptr<FocusableContainer> mainContainer): mainContainer_(mainContainer) {}

    void
    MainLoop::run() {
        mainContainer_->focus();

        int ch = 0; 
        bool received = false;
        do {
            mainContainer_->refresh();
            CursesManager::getInstance().refresh();
            ch = CursesManager::getInstance().getCh();
            received = mainContainer_->receiveKey(ch);
        } while ( received );
    }

}
