* Figure out additional necessary widgets - see gtk for inspiration ( https://developer.gnome.org/gtk3/stable/ch03.html ) -- TODO;ongoing;prio-0
* TextBox: size should be obvious when not focused, v.1 -- DONE;prio-10
* Window: seems to initially print all widgets twice... -- BUG;DONE;prio-10
* Textbox: needs to look differently when in edit mode -- DONE;prio-10
* rename all members to have trailing \_s. -- DONE
* Correctly test for location of curses.h header file -- DONE;prio-10
* Implement Horizontal Menu -- DONE;prio-10
* Implement Vertical Menu -- DONE;prio-10
* Implement Popup Menu -- DONE;prio-10
* Correctly set the cursor -- BUG;DONE;prio-10
* Implement MainLoop -- DONE;prio-10
* Implement additional TextBox features, v.1 -- DONE;prio-10;see todo-notes.txt
* Implement Message Box -- TODO;prio-10
* Implement Confirm Box -- TODO;prio-10
* Implement Select Box -- TODO;prio-10
* Implement Combo Box -- TODO;prio-10
* Implement Radio Button -- TODO;prio-10
* Implement Radio Group -- TODO;prio-10
* Implement Text area -- TODO;prio-10
* Widget::parent\_ needs to be a Container, not a Widget -- TODO;prio-10 
* Rename TextBox::signal\_changed to onAfterChanged or similar -- TODO;prio-10
* #inlcude system header files from only one location -- TODO;prio-10
* All widgets need to react to move(); -- TODO;prio-10
* Add events -- TODO;prio-10
* Figure out how to do "Help" items -- TODO;prio-20
* Correctly autoconfigure location of libsigc++ header file -- TODO;prio-20
* All remaining widgets: figure out how to protected'ize cons but call it from create() -- DONE;prio-10
* Figure out how to do "Context sensitive" items -- TODO;prio-20
* Add override declarations whereever appropriate -- TODO;prio-20;cost-3;codestyle
* Optimize: when refreshing subwidgets, we currently refresh the focused subwidget twice -- TODO;prio-20;cost-3;optimization
* Optimize: use wnoutrefresh and doupdate... the question is, when do we know to do doupdate()? -- TODO;prio-20;optimization;cost-8; id-0002
* Possibly use pImpls to speed up builds? -- TODO;REFLECT;prio-20
* Checkbox: add constructor with frame -- TODO;prio-20
* Consider whether curses functions in curseswindow should run through cursesmanager -- TODO;prio-20
* Add scrolling containers -- TODO;prio-20
* CursesManager: rename getInstance() to get() -- TODO;prio-20;cost-5
* CursesManager: add public move cons -- TODO;prio-20;cost-8
* Implement Focus management -- TODO;prio-20
* Consistently use scoped enums -- TODO;prio-20
* Consistently "=default" or "=delete" or create special functions -- TODO;prio-20
* Use scr\_dump() to make the whole thing testable!! -- TODO;prio-30 (also need to use wborder to set borders that are always printable)
* ^L should refresh everytthing -- TODO;prio-30
* Use curs_set() to hide the cursor -- TODO;prio-30
* Implement Window -- TODO;prio-20
* Implement App with basic loop (AppWindow??? MainWindow??) -- TODO;prio-20
* Reflect the basic class hierarchy -- TODO;prio-20;see-notes
* Implement multi-level undo -- TODO;prio-30
* Use mvvline() and mvwvline to create panes/areas -- TODO;prio-30
* Class hierarchy: Create a common base class for Focusable Widget and FocusableContainer? -- TODO;REFLECT;prio-30;cost-13
* Reflect and do = delete and = default on special functions -- TODO;prio-30;cost-8
* Reflect splitting up namespace and directory laoyut -- TODO;prio-30;cost-5
* Screen - fix ctrl-c/ctrl-w mess; how should it quit? -- REFLECT;TODO;prio-30;cost-2;see-id-0001
* TextBox: size should be obvious when not focused, v.2 -- TODO;prio-40
* TextBox: add colors? (at what point?) -- TODO;prio-40
* TextBox: ... implement color pairs -- TODO;prio-40
* Add flexible keyboard interface -- TODO;prio-40
* Add flexible Color management -- TODO;prio-40
* Add sizing and layouting -- TODO;prio-40
* The whole bloody thing needs to be utf-8 -- TODO;prio-40 -- add_wch(); see ...tests.../getcharcode.c
* Work with actual models -- TODO;prio-40
* Add validators -- TODO;prio-40
* Check out thread safety -- REFLECT;prio-40
* Add an xml ui description language -- REFLECT;prio-40
* Think about real life applications -- REFLECT;prio-50
* Add more configure/autoconf tests -- TODO;prio-50
* Add scriptability -- REFLECT;prio-60
* in src/, redo test/NONEXISTANT will try to redo test/NONEXISTANT.cc, then test/NONEXISTANT.cc.o, then test/NONEXISTANT.cc.o.cc, and so on -- BUG;TODO;prio-60
* Consider if we want a status line (StatusLine widget)? -- TODO;prio-40
