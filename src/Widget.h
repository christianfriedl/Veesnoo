#ifndef NV_WIDGET_H
#define NV_WIDGET_H

#include <sigc++-2.0/sigc++/sigc++.h>

#include "NVBase.h"
#include "Logger.h"
#include "Rect.h"
#include "CursesWindow.h"

namespace nv {

// class ColorAttribute;

// TODO check whether we should derive from NonCopyable
class Widget: public std::enable_shared_from_this<Widget>, public sigc::trackable {
public:
    explicit Widget(const Rect& rect); // from a rectangle
    /*
    Widget(Widget&& other);
    Widget& operator=(Widget&& other);
    */

    virtual ~Widget() {
        Logger::get().log("~Widget() %s", toString().c_str());
    }

    void setParent(const std::weak_ptr<Widget>& parent); 
    virtual void refresh();
    virtual void resize(const int width, const int height);
    virtual void move(const int x, const int y);
    virtual void addString(const std::string& text);
    virtual void addString(const std::string& text, const int x, const int y);
    virtual void addCh(const int ch);
    virtual void addCh(const int ch, const int x, const int y);

    const std::weak_ptr<Widget>& getParent() const;
    bool getIsVisible() const;

    // those return copies of the rects, thus no need for const'ness
    Rect getRect() const;
    virtual Rect getContentRect() const;
    virtual Rect getAbsoluteRect() const; // used in constructor... needs to be virtual
    virtual Rect getAbsoluteContentRect() const;

    virtual const std::string toString() const;


protected:
    Widget();

    void setCWPosition();
    void setCWSize();

    std::unique_ptr<CursesWindow> cursesWindow_;
    Rect rect_; // the original rect, covering all our area - relative to parent
    Rect contentRect_; // the rect clients can paint on - in RELATIVE coords ===> relative to rect
    bool isVisible_;
    std::weak_ptr<Widget> parent_;

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
