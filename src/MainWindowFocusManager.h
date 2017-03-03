#ifndef MAIN_WINDOW_FOCUS_MANAGER_H
#define MAIN_WINDOW_FOCUS_MANAGER_H

#include "ContainerFocusManager.h"
#include "MainWindow.h"

namespace nv {
    class MainWindowFocusManager: public ContainerFocusManager {
        public:
            explicit MainWindowFocusManager(MainWindow *widget);
    };
}

#endif
