#ifndef NV_CHANGE_EVENT_H
#define NV_CHANGE_EVENT_H

#include "Event.h"

namespace nv {
    class ChangeEvent: public Event {
        public:
            ChangeEvent(std::shared_ptr<Widget> const & target);
            virtual ~ChangeEvent();
            const std::string& getName();
            const std::shared_ptr<Widget>& getTarget();

        private:
            const std::string name_;
            const std::shared_ptr<Widget>& target_;
    };
}

#endif
