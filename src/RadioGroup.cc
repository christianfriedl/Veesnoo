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


#include "RadioGroup.h"

namespace veesnoo {
    std::shared_ptr<RadioGroup> RadioGroup::create() {
        return std::make_shared<RadioGroup>();
    }

    void RadioGroup::addButton(std::shared_ptr<RadioButton> button) {
        buttons_.emplace_back(button);
        button->onAfterChange.connect( sigc::mem_fun(*this, &RadioGroup::buttonChanged) );
    }

    void RadioGroup::buttonChanged(const std::shared_ptr<ChangeEvent>& ev) {
        for ( auto button: buttons_ )
            if ( button != ev->getTarget() )
                button->setChecked(false);
    }

}
