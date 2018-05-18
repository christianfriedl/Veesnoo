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


#include <vector>
#include "ChangeEvent.h"
#include "RadioButton.h"

namespace veesnoo {

    /**
     * basic RadioGroup.
     *
     * this is not a widget, nor a container, it is just a managing entity
     * to change all buttons in the group to unchecked if one is checked
     */
    class RadioGroup {
        public:
            static std::shared_ptr<RadioGroup> create();
            void addButton(std::shared_ptr<RadioButton> button);
            void buttonChanged(const std::shared_ptr<ChangeEvent>& ev);
                // TODO removeButton
        private:
            std::vector<std::shared_ptr<RadioButton>> buttons_;
    };

}
