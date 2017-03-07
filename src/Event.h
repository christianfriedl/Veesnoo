#ifndef NV_EVENT_H
#define NV_EVENT_H

#include <string>
#include "Widget.h"

namespace nv {
    class Event {
        public:
            Event();
            virtual ~Event();
            virtual const std::string& getName() = 0;
            virtual const std::shared_ptr<Widget>& getTarget() = 0;

    };
}

#endif
