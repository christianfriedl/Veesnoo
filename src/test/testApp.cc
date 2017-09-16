#include "nvwm.h"

using namespace nv;

int main() {
    auto screen(std::make_shared<Screen>());
    auto screenRect = CursesManager::get().getMaxScreenRect();
    auto window(std::make_shared<Window>(screenRect));
    window->setTitle("Main Window");
    screen->addWidget(window);
    // TODO add Vertical Menu
    
    auto mainLoop(std::make_shared<MainLoop>(screen));
    auto ltb1(std::make_shared<Label>("Text here:", 0, 0));
    window->addWidget(ltb1);
    auto tb1(std::make_shared<TextBox>(20, 0, 20));
    window->addWidget(tb1);
    auto lcb1(std::make_shared<Label>("Check here:", 0, 2));
    window->addWidget(lcb1);
    auto cb1(std::make_shared<CheckBox>(20, 2));
    window->addWidget(cb1);
    auto cb2(std::make_shared<CheckBox>(24, 2));

    auto lrb1(std::make_shared<Label>("Radioi here:", 0, 4));
    window->addWidget(lrb1);
    auto rb11(std::make_shared<RadioButton>(20, 4, "radio_rb11"));
    window->addWidget(rb11);
    auto rb12(std::make_shared<RadioButton>(24, 4, "radio_rb12"));
    window->addWidget(rb12);
    auto rg1(std::make_shared<RadioGroup>());
    rg1->addButton(rb11);
    rg1->addButton(rb12);

    auto lta1(std::make_shared<Label>("Area here:", 0, 6));
    window->addWidget(lta1);
    auto ta1(std::make_shared<TextArea>(Rect(20, 6, 10, 10)));
    window->addWidget(ta1);

    auto lsb1(std::make_shared<Label>("SelectBox here:", 55, 0));
    window->addWidget(lsb1);
    auto sb1(SelectBox::create(window, 75, 0));

    auto sbm1 (std::make_shared<MenuItem>("option1"));
    auto sbm2 (std::make_shared<MenuItem>("option2"));
    auto sbm3 (std::make_shared<MenuItem>("option3"));

    sb1->addItem(sbm1);
    sb1->addItem(sbm2);
    sb1->addItem(sbm3);
    window->addWidget(sb1);

    auto lt1(std::make_shared<Label>("Table here:", 0, 17));
    window->addWidget(lt1);

    auto ta2(std::make_shared<TextArea>(Rect(0, 0, 3, 3)));
    auto t1(std::make_shared<Table>(Rect(20, 17, 80, 28), 3));
    char cts[5][6] = { "cell1", "cell2", "cell3", "cell4", "cell" };
    for (int i = 1; i <= 5; ++i) {
        auto tc1(std::make_shared<Label>(cts[i-1], 0, 0));
        t1->addWidget(tc1);
    }
    t1->addWidget(ta2);
    window->addWidget(t1);


    mainLoop->run();
}
