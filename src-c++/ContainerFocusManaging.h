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

    virtual void addWidget(const Widget& widget) = 0;

    virtual void focusFirst() = 0;
    virtual void focusNext() = 0;
    virtual void focusPrev() = 0;
    virtual void focusThis(const FocusableWidget *widget) = 0;
    virtual void focusThis(const unsigned int index) = 0;
};

}

#endif
