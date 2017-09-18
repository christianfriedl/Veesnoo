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


#ifndef NV_CHANGE_EVENT_H
#define NV_CHANGE_EVENT_H

#include "Event.h"

namespace veesnoo {
    class ChangeEvent: public Event {
        public:
            ChangeEvent(std::shared_ptr<Widget> const & target);
            virtual ~ChangeEvent();
            const std::string& getName() override;
            const std::shared_ptr<Widget>& getTarget() override;

        private:
            const std::string name_;
            const std::shared_ptr<Widget>& target_;
    };
}

#endif
