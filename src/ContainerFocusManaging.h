#ifndef NV_CONTAINER_FOCUS_MANAGING_H
#define NV_CONTAINER_FOCUS_MANAGING_H

#include "FocusableWidget.h"
#include "FocusManaging.h"
#include "FocusableContainer.h"

namespace nv {

class FocusableContainer;

class ContainerFocusManaging: public FocusManaging {
public:
    virtual ~ContainerFocusManaging();

    virtual void focusFirst() = 0;
    virtual void focusNext() = 0;
    virtual void focusPrev() = 0;
    virtual void focusThis(FocusableWidget *widget) = 0;
    virtual void setWidget(FocusableContainer *widget) = 0;
};

}

#endif
