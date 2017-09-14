#ifndef NV_POINT_H
#define NV_POINT_H

class Point {
    public:
        Point(): x_(0), y_(0) {}
        Point(const int x, const int y): x_(x), y_(y) {}
        int getX() const;
        int getY() const;
        void setX(const int x);
        void setY(const int y);

    private:

        int x_;
        int y_;
};

#endif
