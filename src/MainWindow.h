#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "Window.h"

namespace nv {
    class MainWindow: public Window {
        public:
            MainWindow(const Rect& rect, const std::string title = "");
    };
}

#endif
