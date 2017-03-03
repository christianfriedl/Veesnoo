#include "Screen.h"

namespace nv {
    Screen::Screen(): FocusableContainer(Rect(0, 0, 1, 1)) {
        rect = CursesManager::getInstance().getMaxScreenRect(); // TODO why can't I just initialize from this via copy-constr?
        contentRect = rect;
        Logger::get().log("Screen is %s", toString().c_str());
    }
}
