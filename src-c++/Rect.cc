#include "Rect.h"

namespace nv {

inline Rect::Rect(const int x, const int y, const int width, const int height): x(x), y(y), width(width), height(height) { }

inline Rect::Rect(const Rect& other): x(other.x), y(other.y), width(other.width), height(other.height) { }

Rect& Rect::operator=(const Rect& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
    }
        
    return *this;
}

inline void Rect::move(const int x, const int y) {
    this->x = x;
    this->y = y;
}

inline void Rect::resize(const int width, const int height) {
    this->width = width;
    this->height = height;
}

void Rect::setOriginRelativeTo(const Rect& other) {
    x += other.x;
    y += other.y;
}	

}
