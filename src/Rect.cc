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

std::unique_ptr<std::string> Rect::toString() {
    std::ostringstream ostr;
    ostr << "<Rect @ " << this << " <x: " << x << ", y: " << y << ", width: " << width << ", height: " << height << ">>";
    return std::make_unique<std::string>(ostr.str());
}

}
