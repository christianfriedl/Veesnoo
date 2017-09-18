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


#ifndef NV_TEXT_AREA_H
#define NV_TEXT_AREA_H

#include <string>
#include "FocusableWidget.h"
#include "ChangeEvent.h"
#include "Point.h"

namespace nv {
    
enum class TextAreaMode { normal, insert, replace };

/**
 * a basic textarea class
 *
 * our text will be one string; lines will be separated with \n in that string
 *
 * for now, the area will soft-wrap, to avoid the scrolling hassle, at the actual rightmost col
 */
class TextArea : public FocusableWidget {
public:

    TextArea(const Rect& rect);
    bool receiveKey(const int ch) override;
    void addContent() override;
    const std::string& getText();
    void setText(const std::string& text) { text_ = text; }
    void focus() override;
    void blur() override;

    TextAreaMode getMode() { return mode_; }
    void setMode(TextAreaMode mode) { mode_ = mode; }

    sigc::signal<void, const std::shared_ptr<ChangeEvent>&> onAfterChange;

private:
    bool cursorTo(const int pos);
    bool cursorRight();
    bool cursorLeft();
    bool cursorUp();
    bool cursorDown();
    bool cursorToStart();
    bool cursorToEnd();

    inline char fillCharForMode(TextAreaMode mode);
    Point pointFromPosition(const int pos) const;
    int pointToPosition(const Point p) const;
    std::string text_;
    TextAreaMode mode_;
    int cursorPos_;
};

}

#endif
