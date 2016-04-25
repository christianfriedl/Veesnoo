#ifndef NV_CONTAINER_FOCUS_MANAGING_H
#define NV_CONTAINER_FOCUS_MANAGING_H

#include "Widget.h"
#include "FocusableWidget.h"
#include "FocusManaging.h"

namespace nv {

class ContainerFocusManaging: public FocusManaging {
public:
    ContainerFocusManaging() {}
    ContainerFocusManaging(const ContainerFocusManaging&) {}
    virtual ~ContainerFocusManaging();

    virtual void focusFirst() = 0;
    virtual void focusNext() = 0;
    virtual void focusPrev() = 0;
    virtual void focusThis(std::shared_ptr<FocusableWidget> widget) = 0;
    virtual void focusThis(const int index) = 0;
};

}

#endif
