/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Veesnoo is free software; you can redistribute it and/or modify
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


#ifndef NV_RADIO_BUTTON_H
#define NV_RADIO_BUTTON_H

#include <string>
#include "FocusableWidget.h"
#include "ChangeEvent.h"

namespace veesnoo {

enum class RadioButtonState { unchecked, checked };

class RadioButton: public FocusableWidget { // , public KeyReceiving {
public:
    RadioButton(int x, int y, const std::string& value);
    static std::shared_ptr<RadioButton> create(int x, int y, const std::string& value);
    void setFrame(const std::string& frame);
    bool receiveKey(int ch) override;
    void addContent() override;
    bool push(); 
    bool isChecked();
    void setChecked(const bool checked);
    sigc::signal<void, const std::shared_ptr<ChangeEvent>&> onAfterChange;

private:
    RadioButtonState state_;
    std::string frame_;
    const std::string value_;
};

}

#endif
