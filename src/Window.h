#ifndef NV_WINDOW_H
#define NV_WINDOW_H

#include "FocusableContainer.h"

namespace nv {

class Window : public FocusableContainer {
public:
    Window(const Rect& rect);
};

}

#endif
