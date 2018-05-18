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


#ifndef NV_COLOR_ATTRIBUTE_H
#define NV_COLOR_ATTRIBUTE_H

#include "CursesWindow.h"

namespace veesnoo {

    class ColorAttribute {
        public:
            static ColorAttribute *defaultColorAttributes;
            ColorAttribute();
            ColorAttribute(short int fg, short int bg, bool inverse = false, bool bold = false, bool underline = false, bool blink = false);
            ColorAttribute(const ColorAttribute& other);
            ColorAttribute& operator=(const ColorAttribute& other);
            ColorAttribute(ColorAttribute&& other) = delete;
            ColorAttribute& operator=(ColorAttribute&& other) = delete;
            virtual ~ColorAttribute();

            short int getFg() const { return fg_; }
            short int getBg() const { return bg_; }
            bool getInverse() const { return inverse_; }
            void setInverse(bool inverse = true) { inverse_ = inverse; }
            bool getBold() const { return bold_; }
            void setBold(bool bold = true) { bold_ = bold; }
            bool getUnderline() const { return underline_; }
            void setUnderline(bool underline = true) { underline_ = underline; }
            bool getBlink() const { return blink_; }
            void setBlink(bool blink = true) { blink_ = blink; }

            const std::string toString() const;

            int getPairNumber() const { 
                return pairNumber_; 
            }

        private:
            short int fg_, bg_;
            bool inverse_, bold_, underline_, blink_;
            int pairNumber_;

    };

}

#endif
