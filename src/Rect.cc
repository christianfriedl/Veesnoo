#include "Rect.h"
#include "Logger.h"
#include <sstream>

namespace nv {
    Rect::Rect(const int x, const int y, const int width, const int height): x(x), y(y), width(width), height(height) { }

    Rect::Rect(const Rect& other): x(other.x), y(other.y), width(other.width), height(other.height) { }

    Rect& Rect::operator=(const Rect& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            width = other.width;
            height = other.height;
        }
            
        return *this;
    }

    void Rect::move(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    void Rect::resize(const int width, const int height) {
        this->width = width;
        this->height = height;
    }

    void Rect::setOriginRelativeTo(const Rect& other) {
        x += other.x;
        y += other.y;
    }	

    const std::string Rect::toString() const {
        std::ostringstream ostr;
        ostr << "<Rect @ " << std::hex << (unsigned long long int)this << std::dec << " <x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << ">>";
        return ostr.str();
    }

    bool Rect::covers(const Rect& other) {
        LOGMETHOD("x %i, width %i, x2 %i, other.x %i, other.width %i, other.x2 %i", x, width, getX2(), other.x, other.width, other.getX2());
        LOGMETHOD("y %i, height %i, y2 %i, other.y %i, other.height %i, other.y2 %i", y, height, getY2(), other.y, other.height, other.getY2());
        return x <= other.x && y <= other.y && getX2() >= other.getX2() && getY2() >= other.getY2();
    }
}
