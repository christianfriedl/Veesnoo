#ifndef NV_RECT_H
#define NV_RECT_H

namespace nv {

class Rect {

public:

    Rect(int x, int y, int width, int height);
    void move(int ax, int ay);
    void resize(int awidth, int aheight);
    void setOriginRelativeTo(Rect * otherRect);

private:
    int x, y, width, height;
};

}

#endif
