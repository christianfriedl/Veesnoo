#ifndef NV_BASIC_EVENT_H
#define NV_BASIC_EVENT_H

#include "Event.h"

namespace nv {
    class BasicEvent: public Event {
        public:
            BasicEvent(std::shared_ptr<Widget> const & target);
            virtual ~BasicEvent();
            virtual const std::string& getName() override;
            virtual const std::shared_ptr<Widget>& getTarget() override;

        private:
            const std::string name_;
            const std::shared_ptr<Widget>& target_;
    };
}

#endif
