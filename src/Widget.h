/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#ifndef NV_WIDGET_H
#define NV_WIDGET_H

#include <memory>
#include <sigc++/sigc++.h>

#include "NVBase.h"
#include "Logger.h"
#include "Rect.h"
#include "CursesWindow.h"
#include "ColorAttribute.h"

namespace veesnoo {

// class ColorAttribute;

class Widget: public std::enable_shared_from_this<Widget>, public sigc::trackable {
public:
    explicit Widget(const Rect& rect); // from a rectangle
    static std::shared_ptr<Widget> create(const Rect& rect);
    /*
    Widget(Widget&& other);
    Widget& operator=(Widget&& other);
    */

    virtual ~Widget() {
    }

    void setParent(const std::weak_ptr<Widget>& parent); 
    virtual void refresh();
    virtual void addContent();
    virtual void resize(const int width, const int height);
    virtual void move(const int x, const int y);
    virtual void addString(const std::string& text);
    virtual void addString(const std::string& text, const int x, const int y);
    virtual void addCh(const int ch);
    virtual void addCh(const int ch, const int x, const int y);
    virtual void startColorAttribute(const ColorAttribute& attribute);
    virtual void endColorAttribute(const ColorAttribute& attribute);

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
    virtual const ColorAttribute& getContentColorAttribute();
    virtual const ColorAttribute& getBorderColorAttribute();


protected:
    Widget();

    void setCWPosition(const Rect& absoluteRect);
    void setCWSize();
    Rect getParentAbsoluteContentRect() const;

    void fillBackground(const int ch, const ColorAttribute& attribute);
    void addBorder();

    int objectId_;
    std::unique_ptr<CursesWindow> cursesWindow_;
    Rect rect_; // the original rect, covering all our area - relative to parent
    Rect contentRect_; // the rect clients can paint on - in RELATIVE coords ===> relative to rect
    bool isVisible_;
    std::weak_ptr<Widget> parent_;
    std::string colorTag_;


private:

    void moveRect(const int ax, const int ay);


};


}

#endif
