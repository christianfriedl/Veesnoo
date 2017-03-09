#include "Widget.h"
#include "BasicEvent.h"

namespace nv {
    BasicEvent::BasicEvent(std::shared_ptr<Widget> const & target):
        Event(), name_("basic"), target_(target) {}
    BasicEvent::~BasicEvent() {}
    const std::string& BasicEvent::getName() { return name_; }
    const std::shared_ptr<Widget>& BasicEvent::getTarget() { return target_; }
}
