#include "MainWindow.h"
#include "MainWindowFocusManager.h"

namespace nv {
    MainWindow::MainWindow(const Rect& rect, const std::string title) : Window(rect, title) {
        Logger::get().log("new MainWindow @ %ld %s", toString().c_str());
        delete focusManager_;
        focusManager_ = new MainWindowFocusManager(this);
    }
}
