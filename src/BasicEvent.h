#ifndef NV_BASIC_EVENT_H
#define NV_BASIC_EVENT_H

#include "Event.h"

namespace nv {
    class BasicEvent: public Event {
        public:
            BasicEvent(std::shared_ptr<Widget> const & target);
            virtual ~BasicEvent();
            const std::string& getName();
            const std::shared_ptr<Widget>& getTarget();

        private:
            const std::string name_;
            const std::shared_ptr<Widget>& target_;
    };
}

#endif
