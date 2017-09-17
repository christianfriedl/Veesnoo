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


#ifndef NV_RECT_H
#define NV_RECT_H

#include <string>
#include <memory>

#include "Point.h"

namespace nv {

class Rect {

public:

    Rect(): x(0), y(0), width(0), height(0) {}
    Rect(const int x, const int y, const int width, const int height);
    Rect(const Rect& other);
    Rect& operator=(const Rect& other);


    void move(const int ax, const int ay);
    void resize(const int width, const int height);
    void setOriginRelativeTo(const Rect& other);

    int getX() const { return x; } 
    int getY() const { return y; } 
    int getWidth() const { return width; } 
    int getHeight() const { return height; } 

    int getX2() const { return x + width; } 
    int getY2() const { return y + height; } 

    Point getUpperLeftPoint() { return Point(x, y); }

    /**
     * return true if THIS Rect completely covers the other
     */
    bool covers(const Rect& other);

    const std::string toString() const;

private:
    int x, y, width, height;
};

}

#endif
