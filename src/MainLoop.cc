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
            Logger::get().log("add start of MainLoop(%llx)::do loop$ has subWidgets length %i", this, mainContainer_->getSubWidgets().size());
            mainContainer_->refresh();
            CursesManager::getInstance().refresh();
            ch = CursesManager::getInstance().getCh();
            received = mainContainer_->receiveKey(ch);
        } while ( false ); //////
    }

    std::shared_ptr<FocusableContainer>& MainLoop::getContainer() {
        return mainContainer_;
    }
}
