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


#include "nvwm.h"

using namespace veesnoo;

int main() {
    auto screen(std::make_shared<Screen>());
    // screen->setContentFocusedColorAttribute(std::make_shared<ColorAttribute>(COLOR_YELLOW, COLOR_BLUE));
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    window->setTitle("Main Window");
    screen->addWidget(window);
    // TODO add Vertical Menu
    
    auto mainLoop(std::make_shared<MainLoop>(screen));
    auto ltb1(Label::create("Text here:", 0, 0));
    window->addWidget(ltb1);
    auto tb1(TextBox::create(20, 0, 20));
    tb1->setText("textbox");
    window->addWidget(tb1);
    auto lcb1(Label::create("Check here:", 0, 2));
    window->addWidget(lcb1);
    auto cb1(CheckBox::create(20, 2));
    window->addWidget(cb1);
    auto cb2(CheckBox::create(24, 2));

    auto lrb1(Label::create("Radioi here:", 0, 4));
    window->addWidget(lrb1);
    auto rb11(RadioButton::create(20, 4, "radio_rb11"));
    window->addWidget(rb11);
    auto rb12(RadioButton::create(24, 4, "radio_rb12"));
    window->addWidget(rb12);
    auto rg1(RadioGroup::create());
    rg1->addButton(rb11);
    rg1->addButton(rb12);

    auto lta1(Label::create("Area here:", 0, 6));
    window->addWidget(lta1);
    auto ta1(TextArea::create(Rect(20, 6, 10, 10)));
    window->addWidget(ta1);

    auto lsb1(Label::create("SelectBox here:", 55, 0));
    window->addWidget(lsb1);
    auto sb1(SelectBox::create(window, 75, 0));

    auto sbm1 (MenuItem::create("option1"));
    auto sbm2 (MenuItem::create("option2"));
    auto sbm3 (MenuItem::create("option3"));

    sb1->addItem(sbm1);
    sb1->addItem(sbm2);
    sb1->addItem(sbm3);
    window->addWidget(sb1);

    auto lt1(Label::create("Table here:", 0, 17));
    window->addWidget(lt1);

    auto ta2(TextArea::create(Rect(0, 0, 3, 3)));

    auto t1(Table::create(Rect(20, 17, 80, 28), 3));
    char cts[5][6] = { "cell1", "cell2", "cell3", "cell4", "cell" };
    for (int i = 1; i <= 5; ++i) {
        auto tc1(Label::create(cts[i-1], 0, 0));
        t1->addWidget(tc1);
    }
    t1->addWidget(ta2);
    window->addWidget(t1);


    mainLoop->run();
}
