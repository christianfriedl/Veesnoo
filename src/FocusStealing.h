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


#ifndef NV_FOCUS_STEALING_H
#define NV_FOCUS_STEALING_H


class Focusable;
namespace veesnoo {
    /**
     * interface for things that will steal the focus,
     * and thus need to give it back on close
     */

    class FocusStealing {
        public:
            virtual ~FocusStealing() {}
            virtual bool open() = 0;
            virtual bool close() = 0;
            virtual const std::shared_ptr<Focusable>& getPreviouslyFocusedWidget() const = 0;
    };
}

#endif
