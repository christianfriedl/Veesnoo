#include "Window.h"
#include "ConfirmBox.h"

using namespace nv;

void isClosed(const std::shared_ptr<BasicEvent>& ev)
{
    Logger::get().log("closed event received");
}

void isOk(const std::shared_ptr<BasicEvent>& ev)
{
    Logger::get().log("ok event received");
}

void isCancel(const std::shared_ptr<BasicEvent>& ev)
{
    Logger::get().log("cancel event received");
}


int main() {
    auto w1 = Window::create(Rect(10, 10, 100, 20), "fenst");
    auto mb1 = ConfirmBox::create("rhabarber", "rhubarbh");
    mb1->onAfterClose.connect(sigc::ptr_fun(isClosed) );
    mb1->onOkPushed.connect(sigc::ptr_fun(isOk) );
    mb1->onCancelPushed.connect(sigc::ptr_fun(isCancel) );
    w1->addWidget(mb1);
    mb1->layout();
    do {
        w1->refresh();
        int ch = CursesManager::get().getCh();
        w1->receiveKey(ch);
    } while (true);
}
