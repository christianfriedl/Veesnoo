#ifndef NV_WIDGET_H
#define NV_WIDGET_H

#include <ncursesw/ncurses.h>
#include <string>
#include <iostream>

#include "Rect.h"
#include "CursesWindow.h"

namespace nv {

// class ColorAttribute;

class Widget {
public:
    Widget(): cw(NULL), rect(NULL), contentRect(NULL), absoluteContentRect(NULL), isVisible(false), parent(NULL) {}
    Widget(const Rect& rect);
    virtual ~Widget();
    virtual void refresh();
    virtual void resize(const int width, const int height);
    virtual void move(const int x, const int y);
    virtual void addString(const std::string& text);
    virtual void addString(const std::string& text, const int x, const int y);
    virtual void addCh(const int ch);
    virtual void addCh(const int ch, const int x, const int y);

    const Rect& getAbsoluteContentRect() const; // returns a heap object that clients need to delete!
    const Rect& getAbsoluteRect() const; // returns a heap object that clients need to delete!


protected:
    void setCWPosition();
    void setCWSize();
    const Rect& getParentAbsoluteContentRect() const;
    virtual void recalculateAbsoluteRects();

    CursesWindow *cw;
    Rect *rect; // the original rect
    Rect *contentRect; // the rect clients can paint on
    Rect *absoluteRect;
    Rect *absoluteContentRect;
    bool isVisible;
    Widget *parent;


private:
    Widget(const Widget&) {}

    /*
    @property(weak) ColorAttribute* contentColAttr;
    @property(weak) ColorAttribute* borderColAttr;
    @property(weak) ColorAttribute* focusedColAttr;
    @property(weak) ColorAttribute* focusedBorderColAttr;
    @property(weak) ColorAttribute* activeColAttr;
    */
    void moveRect(const int ax, const int ay);


};

}

#endif
