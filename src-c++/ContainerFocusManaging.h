#ifndef NV_CONTAINER_FOCUS_MANAGING_H
#define NV_CONTAINER_FOCUS_MANAGING_H

#include "Widget.h"
#include "FocusManaging.h"

namespace nv {

class ContainerFocusManaging: public FocusManaging {
public:
    ContainerFocusManaging() {}
    ContainerFocusManaging(const ContainerFocusManaging&) {}
    virtual ~ContainerFocusManaging();

    virtual void addWidget(const Widget& widget) = 0;
};

}

#endif
