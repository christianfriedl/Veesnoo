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


#ifndef NV_CONTAINER_FOCUS_MANAGING_H
#define NV_CONTAINER_FOCUS_MANAGING_H

#include "FocusableWidget.h"
#include "FocusManaging.h"
#include "FocusableContainer.h"

namespace nv {

class FocusableContainer;

class ContainerFocusManaging: public FocusManaging {
public:
    virtual ~ContainerFocusManaging();

    virtual void focusFirst() = 0;
    virtual void focusNext() = 0;
    virtual void focusPrev() = 0;
    virtual void focusThis(FocusableWidget *widget) = 0;
    virtual void setWidget(FocusableContainer *widget) = 0;
};

}

#endif
