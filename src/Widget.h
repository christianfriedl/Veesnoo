#ifndef NV_WIDGET_H
#define NV_WIDGET_H

#include <memory>
#include <sigc++/sigc++.h>

#include "NVBase.h"
#include "Logger.h"
#include "Rect.h"
#include "CursesWindow.h"
#include "ColorAttribute.h"

namespace nv {

// class ColorAttribute;

// TODO check whether we should derive from NonCopyable
class Widget: public std::enable_shared_from_this<Widget>, public sigc::trackable {
public:
    explicit Widget(const Rect& rect); // from a rectangle
    static std::shared_ptr<Widget> create(const Rect& rect);
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
    virtual void startColorAttribute(const ColorAttribute& attribute);
    virtual void endColorAttribute(const ColorAttribute& attribute);
    virtual void startColorAttribute(std::shared_ptr<ColorAttribute> attribute);
    virtual void endColorAttribute(std::shared_ptr<ColorAttribute> attribute);

    const std::weak_ptr<Widget>& getParent() const;
    bool getIsVisible() const;
    bool getIsVisibleBubbling() const; // TODO this naming...
    virtual void show();
    virtual void hide();

    // those return copies of the rects, thus no need for const'ness
    Rect getRect() const;
    virtual Rect getContentRect() const;
    virtual Rect getAbsoluteRect() const; // used in constructor... needs to be virtual
    virtual Rect getAbsoluteContentRect() const;

    virtual const std::string toString() const;
    std::shared_ptr<ColorAttribute> getPrimaryColorAttribute();


protected:
    Widget();

    void setCWPosition(const Rect& absoluteRect);
    void setCWSize();
    Rect getParentAbsoluteContentRect() const;

    std::unique_ptr<CursesWindow> cursesWindow_;
    Rect rect_; // the original rect, covering all our area - relative to parent
    Rect contentRect_; // the rect clients can paint on - in RELATIVE coords ===> relative to rect
    bool isVisible_;
    std::weak_ptr<Widget> parent_;
    std::shared_ptr<ColorAttribute> primaryColorAttribute_;
    void fillBackground(const int ch, std::shared_ptr<ColorAttribute> attribute);
    void addBorder();

private:

    void moveRect(const int ax, const int ay);


};


}

#endif
