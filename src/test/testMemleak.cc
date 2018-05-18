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


#include "nvwm.h"
#include <algorithm>

using namespace veesnoo;

int main() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    std::vector<std::shared_ptr<SelectBox>> boxes;
    for (int y = 0; y < 9; y += 2) { 
        for (int x = 0; x < 10; x += 8) {
            auto sb = SelectBox::create(window, x, y);
            boxes.emplace_back(sb);
            window->addWidget(sb);
        }
    }
    std::for_each(boxes.begin(), boxes.end(), [](auto box) { box->receiveKey(' '); box->getMenu()->close(); });
    boxes[0]->focus();
    window->refresh();
    getch();
}
