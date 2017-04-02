#include "MainLoop.h"

namespace nv {

    MainLoop::MainLoop(std::shared_ptr<FocusableContainer> mainContainer): mainContainer_(mainContainer) {
        Logger::get().log("MainLoop::MainLoop(...), has subWidgets length %i", mainContainer->getSubWidgets().size());
    }

    void
    MainLoop::run() {
        Logger::get().log("add start of MainLoop(%llx)::run(), has subWidgets length %i", this, mainContainer_->getSubWidgets().size());
        mainContainer_->focus();

        int ch = 0; 
        bool received = false;
        do {
            mainContainer_->refresh();
            ch = CursesManager::get().getCh();
            received = mainContainer_->receiveKey(ch);
        } while ( received );
    }

    std::shared_ptr<FocusableContainer>& MainLoop::getContainer() {
        return mainContainer_;
    }
}
