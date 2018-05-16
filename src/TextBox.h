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


#ifndef NV_TEXT_BOX_H
#define NV_TEXT_BOX_H

#include <string>
#include "FocusableWidget.h"
#include "ChangeEvent.h"

namespace veesnoo {
    
enum class TextBoxMode { normal, insert, replace };

class TextBox : public FocusableWidget {
public:

    TextBox(const int x, const int y, const int width);
    static std::shared_ptr<TextBox> create(const int x, const int y, const int width);
    bool receiveKey(const int ch) override;
    void addContent() override;
    const std::string& getText();
    void setText(const std::string& text) { text_ = text; }
    inline int getCursorPos();
    void focus() override;

    TextBoxMode getMode() { return mode_; }
    void setMode(TextBoxMode mode) { mode_ = mode; }

    sigc::signal<void, const std::shared_ptr<ChangeEvent>&> onAfterChange;

    virtual std::shared_ptr<ColorAttribute> getContentColorAttribute() override;

private:
    bool cursorTo(int x);
    bool cursorRight();
    bool cursorLeft();
    bool cursorToStart();
    bool cursorToEnd();

    char fillCharForMode(TextBoxMode mode);
    std::string text_;
    TextBoxMode mode_;
    unsigned long cursorX_;
    unsigned long startX_;
    std::shared_ptr<ColorAttribute> contentEditColorAttribute_;

};

}

#endif
