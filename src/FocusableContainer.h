#ifndef NV_FOCUSABLE_CONTAINER_H
#define NV_FOCUSABLE_CONTAINER_H

#include <memory>
#include "Focusable.h"
#include "Focusable.h"
#include "Container.h"
#include "ContainerFocusManager.h"

namespace nv {

class FocusableContainer: public Focusable, public Container {
public:
    explicit FocusableContainer(const Rect& rect): Focusable(), Container(rect), focusManager_(this) { }

    FocusableContainer(const Rect& rect, const ContainerFocusManager& focusManager): Focusable(), Container(rect), focusManager_(focusManager) { }
    void setFocusManager(const ContainerFocusManager& focusManager) { focusManager_ = focusManager; }

    virtual ~FocusableContainer() {}

    virtual bool receiveKey(int ch);

    virtual bool isFocused() const { return focusManager_.isFocused(); }
    virtual void focus() { Logger::get().log("fc @ %lld is focused", this); focusManager_.focus(); }
    virtual void deFocus() { focusManager_.deFocus(); }

    void focusFirst() { focusManager_.focusFirst(); }
    void focusNext() { focusManager_.focusNext(); }
    void focusPrev() { focusManager_.focusPrev(); }
    void focusThis(std::shared_ptr<Focusable>& widget) { focusManager_.focusThis(widget); }

protected:
    ContainerFocusManager focusManager_;
private:
};

}
#endif
