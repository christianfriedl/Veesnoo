/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Veesnoo is free software; you can redistribute it and/or modify
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


#ifndef NV_FOCUS_MANAGING_H
#define NV_FOCUS_MANAGING_H

namespace veesnoo {

class FocusManaging {
public:
    virtual ~FocusManaging() {}

    virtual bool receiveKey(int ch) = 0;
    virtual void focus() = 0;
    virtual void blur() = 0;
    virtual bool isFocused() const = 0;

};

}

#endif
