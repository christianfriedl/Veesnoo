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


#include <ncursesw/ncurses.h>
#include "TextArea.h"
#include "Logger.h"

using namespace veesnoo;

void is_changed(const std::shared_ptr<ChangeEvent>& ev)
{
	endwin();
    auto tgt = std::static_pointer_cast<TextArea>(ev->getTarget());
    std::cout << "This is the changed handler, Textbox was changed to: " << tgt->getText() << std::endl;
}

void test1() {
    TextArea t1(Rect(1, 1, 20, 10));
    t1.refresh();
    getch();
    t1.focus();
    t1.refresh();
    getch();
    t1.receiveKey('i');
    t1.receiveKey('x');
    t1.refresh();
    getch();
}

int main() {
    auto t1(std::make_shared<TextArea>(Rect(1, 1, 10, 10)));
    t1->onAfterChange.connect( sigc::ptr_fun(is_changed) );
    t1->setText("abcde");
    t1->focus();
    t1->refresh();
    int ch = 0;
    while ( true ) {
        ch = getch();
        bool received = t1->receiveKey(ch);
        t1->refresh();
        if ( !received && ch == Key_Esc )
            break;
    }
    LOG("text is: '%s'", t1->getText().c_str());
}
