#ifndef NV_WIDGET_H
#define NV_WIDGET_H

// #include <ncursesw/ncurses.h>
#include <ncurses.h>
#include <string>
#include <iostream>
#include <memory>

#include "Logger.h"
#include "Rect.h"
#include "CursesWindow.h"

namespace nv {

// class ColorAttribute;

// TODO check whether we should derive from NonCopyable
class Widget {
public:
    explicit Widget(const Rect& rect); // from a rectangle
    /*
    Widget(Widget&& other);
    Widget& operator=(Widget&& other);
    */

    virtual ~Widget() {
        Logger::get().log("~Widget() %s", toString().c_str());
    }

    void setParent(Widget *parent); 
    virtual void refresh();
    virtual void resize(const int width, const int height);
    virtual void move(const int x, const int y);
    virtual void addString(const std::string& text);
    virtual void addString(const std::string& text, const int x, const int y);
    virtual void addCh(const int ch);
    virtual void addCh(const int ch, const int x, const int y);

    std::shared_ptr<Widget> getParent() const;
    bool getIsVisible() const;

    Rect getRect() const;

    virtual Rect getContentRect() const;
    virtual Rect getAbsoluteRect() const; // used in constructor... needs to be virtual
    virtual Rect getAbsoluteContentRect() const;

    virtual const std::string toString() const;


protected:
    Widget(): rect(0, 0, 1, 1), contentRect(0, 0, 1, 1), isVisible(false), parent_(nullptr) {}

    void setCWPosition();
    void setCWSize();

    std::unique_ptr<CursesWindow> cw;
    Rect rect; // the original rect, covering all our area - relative to parent
    Rect contentRect; // the rect clients can paint on - in RELATIVE coords ===> relative to rect
    bool isVisible;
    Widget *parent_;

private:

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
