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


#include "Widget.h"
#include "ChangeEvent.h"

namespace nv {
    ChangeEvent::ChangeEvent(std::shared_ptr<Widget> const & target):
        Event(), name_("change"), target_(target) {}
    ChangeEvent::~ChangeEvent() {}
    const std::string& ChangeEvent::getName() { return name_; }
    const std::shared_ptr<Widget>& ChangeEvent::getTarget() { return target_; }
}
