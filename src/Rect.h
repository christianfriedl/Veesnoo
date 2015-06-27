#ifndef NV_RECT_H
#define NV_RECT_H

namespace nv {

class Rect {

public:

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

private:
    int x, y, width, height;
};

}

#endif
