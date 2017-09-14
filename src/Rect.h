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

    std::unique_ptr<const std::string> toString() const;

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

private:
    int x, y, width, height;
};

}

#endif
