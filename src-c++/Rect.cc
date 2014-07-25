#include "Rect.h"

namespace nv {

Rect::Rect(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Rect::move(int x, int y) {
    this->x = x;
    this->y = y;
}

void Rect::resize(int width, int height) {
    this->width = width;
    this->height = height;
}

void Rect::setOriginRelativeTo(Rect *otherRect) {
    this->x += otherRect->getX();
    this->y += otherRect->getY();
}	

}
