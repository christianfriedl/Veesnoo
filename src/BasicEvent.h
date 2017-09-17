/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


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
