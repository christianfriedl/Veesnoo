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
    Widget(const Rect& rect);
    virtual ~Widget();
    void setParent(const Widget& parent); 
    virtual void refresh();
    virtual void resize(const int width, const int height);
    virtual void move(const int x, const int y);
    virtual void addString(const std::string& text);
    virtual void addString(const std::string& text, const int x, const int y);
    virtual void addCh(const int ch);
    virtual void addCh(const int ch, const int x, const int y);

    const Widget& getParent() const;
    const bool getVisible() const;

    virtual const Rect& getRect() const;
    virtual const Rect& getContentRect() const;
    virtual const Rect& getAbsoluteRect() const;
    virtual const Rect& getAbsoluteContentRect() const; 

protected:
    Widget(): cw(NULL), rect(NULL), contentRect(NULL), absoluteContentRect(NULL), isVisible(false), parent_(NULL) {}

    void setCWPosition();
    void setCWSize();

    void calculateAbsoluteRects();
    void calculateRects();

    virtual void calculateContentRect();

    CursesWindow *cw;
    Rect *rect; // the original rect
    Rect *contentRect; // the rect clients can paint on
    Rect *absoluteRect;
    Rect *absoluteContentRect;
    bool isVisible;
    const Widget *parent_;


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

inline
const Widget& 
Widget::getParent() const {
    return *parent_;
}

inline
const bool 
Widget::getVisible() const {
    return isVisible;
}

inline
const Rect& 
Widget::getRect() const {
    return *rect;
}

inline
const Rect& 
Widget::getContentRect() const {
    return *contentRect;
}

inline
const Rect& 
Widget::getAbsoluteRect() const {
    return *absoluteRect;
}

inline
void
Widget::setParent(const Widget& parent) {
    parent_ = &parent; 
}

}

#endif
