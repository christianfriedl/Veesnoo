#include "Widget.h"
#include "ChangeEvent.h"

namespace nv {
    ChangeEvent::ChangeEvent(std::shared_ptr<Widget> const & target):
        Event(), name_("change"), target_(target) {}
    ChangeEvent::~ChangeEvent() {}
    const std::string& ChangeEvent::getName() { return name_; }
    const std::shared_ptr<Widget>& ChangeEvent::getTarget() { return target_; }
}
