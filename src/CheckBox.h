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


#ifndef NV_CHECKBOX_H
#define NV_CHECKBOX_H

#include <string>
#include "FocusableWidget.h"

namespace nv {

typedef enum { CheckboxState_unchecked, CheckboxState_checked } CheckboxState;

class CheckBox: public FocusableWidget {
public:
    CheckBox(int x, int y);
    void setFrame(const std::string& frame);
    void addContent() override;
    bool push(); 
    bool isChecked();
    bool receiveKey(int ch) override;

private:
    CheckboxState state_;
    std::string frame_;
};

}

#endif
