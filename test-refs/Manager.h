#ifndef FOO_H
#define FOO_H

#include <iostream>

class Widget;

class Manager {
    public:
        Manager();
        ~Manager();
        void setWidget(Widget *w);

        int j_;
        Widget *widget_;

        friend std::ostream& operator<<(std::ostream& os, const Manager& foo);
};

#endif
