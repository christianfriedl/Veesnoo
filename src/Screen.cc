#include <string.h>
#include "Screen.h"

namespace nv {
    Screen::Screen(): FocusableContainer(Rect(0, 0, 1, 1)) {
        Logger::get().log("new Screen()");
        rect_ = CursesManager::get().getMaxScreenRect(); // TODO why can't I just initialize from this via copy-constr?
        contentRect_ = rect_;
        Logger::get().log("Screen is %s", toString().c_str());
    }

    bool Screen::receiveKey(int ch) {
        const char * const name = CursesManager::get().getKeyName(ch);
        if ( strncmp(name, "^C", 2) == 0 )
            return false;
        FocusableContainer::receiveKey(ch); // we ignore the rv here
        return true;
    }
}
