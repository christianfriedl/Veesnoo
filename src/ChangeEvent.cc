#include "ChangeEvent.h"

namespace nv {
    ChangeEvent::ChangeEvent(const std::string name, const std::shared_ptr<Widget>& target):
        Event(), name_(name), target_(target) {}
    const std::string& ChangeEvent::getName() { return name_; }
    const std::shared_ptr<Widget>& ChangeEvent::getTarget() { return target_; }
}
