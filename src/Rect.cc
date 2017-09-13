#include "Rect.h"
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

    std::unique_ptr<const std::string> Rect::toString() const {
        std::ostringstream ostr;
        ostr << "<Rect @ " << std::hex << (unsigned long long int)this << std::dec << " <x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << ">>";
        return std::make_unique<const std::string>(ostr.str());
    }

    bool Rect::covers(const Rect& other) {
        return x <= other.x && y <= other.y && getX2() >= other.getX2() && getY2() >= other.getY2();
    }
}
