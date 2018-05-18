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


#include "CursesWindow.h"
#include "Button.h"

using namespace veesnoo;

void is_pushed(const std::shared_ptr<BasicEvent>& ev) // ignore 
{
	endwin();
    std::cout << "Was pushed" << std::endl;
}
int main() {
    auto b1(std::make_shared<Button>("rhabarber", 2, 2));
    b1->onAfterPush.connect( sigc::ptr_fun(is_pushed) );
    b1->refresh();
    Button b2("axaluber hidraful", 20, 2);
    b2.refresh();
    Button b3("hedrupholl", 2, 3);
    b3.refresh();
    Button b4("examphhimpf", 20, 3);
    b4.refresh();
    getch();

    b1->focus();
    b1->refresh();
    getch();

    b1->receiveKey(' ');
    b1->refresh();
    getch();
}
