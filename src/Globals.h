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


#ifndef NV_GLOBALS_H
#define NV_GLOBALS_H

#include "ColorTheme.h"

namespace veesnoo {

    class Globals {
        public:
            static Globals& get();
            int nextObjectId();

            ColorTheme colorTheme;
            
        private:
            Globals(); 
            ~Globals();

            Globals(const Globals&);
            Globals& operator=(const Globals&);
            int objectId_;
    };

}

#endif
