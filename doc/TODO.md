* Start with colors 
* (continuous) consistently use LOG macro -- TODO;prio-20;cost-3;codestyle
* BUG: MesageBox has no create(), so test does not compile -- TODO;prio-20;cost-2;BUG
* Better organize source code -- TODO;prio-20
* Implement Tabbed Page -- TODO;prio-10
* Implement Table -- TODO;prio-10
* Implement a Point class and use it for overloaded move() -- TODO;prio-10
* Implement a Point class and use it for overloaded resize() -- TODO;prio-10
* Implement a factory for all widgets -- TODO;prio-10
* focus order needs to be optionally determined by a tabIndex -- TODO;prio-20
* getIsVisibleBubbling() should not be in concrete widgets -- TODO;prio-10
* replace all occurrences of Logger.log() with LOGMETHOD -- TODO;prio-10
* Be able to define custom focus order -- TODO;prio-20
* BUG: if TableRow is constructed with rect(0,0,1,1), but inside the test app (see test/testTable.cc), then the tableCell will be displayed at 0,0 instead of 1,1 -- TODO;BUG;prio-20
* valgrind shows that SelectBox leaks memory, but only once popup opens -- TODO;prio-10
** try and remove selectedItem_, probably solving it; otherwise turn menu_ into wek ref?
* Create .so instead of .a, and use it in test/ -- TODO;prio-10
* Widget::parent\_ needs to be a Container, not a Widget, so we don't have to cast every access -- TODO;prio-10 
* All widgets need to react to move(); -- TODO;prio-10
* Add onAfterFocus to FocusableXXX -- TODO;prio-10;events
* focus() and deFocus() should return bool -- TODO;prio-10
* figure out at what point we need to paint once over everything (set default colors in terminal emu to see the difference!) -- TODO;prio-10
* Figure out how to do "Help" items -- TODO;prio-20
* TextArea needs to be scrollable -- TODO;prio-20
* Unify Constructors -- TODO;prio-20;cost-5;#unifyconstructors
* Merge ContainerFocusManaging into FocusManaging -- TODO;prio-20
* Create a simple wrapper around ConfirmBox that just returns ok or cancel -- TODO;prio-20
* Create a simple wrapper around MessageBox that just returns -- TODO;prio-20
* Possibly rename FocusStealing to Closable, and move onClose into it? -- TODO;prio-20
* Correctly autoconfigure location of libsigc++ header file -- TODO;prio-20
* Figure out how to do "Context sensitive" items -- TODO;prio-20
* Optimize: when refreshing subwidgets, we currently refresh the focused subwidget twice -- TODO;prio-20;cost-3;optimization
* Optimize: use wnoutrefresh and doupdate... the question is, when do we know to do doupdate()? -- TODO;prio-20;optimization;cost-8; id-0002
* Possibly use pImpls to speed up builds? -- TODO;REFLECT;prio-20
* ContainerFocusManager does not implement an interface -- TODO;prio-20;codestyle;#cfminterface
* Checkbox: add constructor with frame -- TODO;prio-20
* Consider whether curses functions in curseswindow should run through cursesmanager -- TODO;prio-20
* Add scrolling containers -- TODO;prio-20
* CursesManager: add public move cons -- TODO;prio-20;cost-8
* Consistently use scoped enums -- TODO;prio-20
* Consistently "=default" or "=delete" or create special functions -- TODO;prio-20
* Use scr\_dump() to make the whole thing testable!! -- TODO;prio-30 (also need to use wborder to set borders that are always printable)
* ^L should refresh everytthing -- TODO;prio-30
* Rename setCWSize etc to something better -- TODO;prio-30
* Use curs_set() to hide the cursor -- TODO;prio-30
* Implement multi-level undo -- TODO;prio-30
* Use mvvline() and mvwvline to create panes/areas -- TODO;prio-30
* Class hierarchy: Create a common base class for Focusable Widget and FocusableContainer? -- TODO;REFLECT;prio-30;cost-13
* Reflect and do = delete and = default on special functions -- TODO;prio-30;cost-8
* Reflect splitting up namespace and directory laoyut -- TODO;prio-30;cost-5
* Screen - fix ctrl-c/ctrl-w mess; how should it quit? -- REFLECT;TODO;prio-30;cost-2;see-id-0001
* Implement Combo Box -- TODO;prio-40;id-0003
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
* Add a json description language -- REFLECT;prio-40
* Think about real life applications -- REFLECT;prio-50
* Add more configure/autoconf tests -- TODO;prio-50
* Add scriptability -- REFLECT;prio-60
* in src/, redo test/NONEXISTANT will try to redo test/NONEXISTANT.cc, then test/NONEXISTANT.cc.o, then test/NONEXISTANT.cc.o.cc, and so on -- BUG;TODO;prio-60
* Consider if we want a status line (StatusLine widget)? -- TODO;prio-40
* Add an on("string"...) method like jquery -- TODO;prio-30
* Figure out additional necessary widgets - see gtk for inspiration ( https://developer.gnome.org/gtk3/stable/ch03.html ) -- TODO;ongoing;prio-0

## DONE TASKS

* Reflect the basic class hierarchy -- DONE;prio-20;see-notes
* BUG: Focused element inside Table will never yield focus, because parent focusable will just keep its focus -- DONE;prio-10;BUG
* We need a better default focus order -- DONE;prio-10
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
* Implement Message Box -- DONE;prio-10
* Check all the header gaurds for errors -- DONE;prio-10
* Rename TextBox::signal\_changed to onAfterChanged or similar -- DONE;prio-10
* #inlcude system header files from only one location -- REJECTED;prio-10
* Implement Confirm Box -- DONE;prio-10
* We need to figure out what to do after FocusableContainer gets removed from parent -- DONE;prio-10
* Implement Radio Button -- DONE;prio-10
* Implement Select Box -- DONE;prio-10
* rename deFocus() to blur() -- DONE;prio-10;#focusblur
* Add override declarations whereever appropriate -- DONE;prio-20;cost-3;codestyle;#overridedecls
* BUG: Selectbox cannot be opened the 2nd time -- DONE;prio-10;cost-5;BUG
* Move closing code of MessageBox into Widget::close() -- REJECTED;prio-10
* Move closing code of ConfirmBox into Widget::close() -- REJECTED;prio-10
* Unify Case: SelectBox vs. Checkbox --> CheckBox -- DONE;prio-30;cost-1;codestyle;#checkboxcase
* Implement Focus management -- DONE;prio-20
* Implement Radio Group -- DONE;prio-10
* Implement Text area -- DONE;prio-10
* All remaining widgets: figure out how to protected'ize cons but call it from create() -- DONE;prio-10
* Implement Window -- DONE;prio-20
* Implement App with basic loop (AppWindow??? MainWindow??) -- DONE;prio-20
* CursesManager: rename getInstance() to get() -- DONE;prio-20;cost-5
* If we cannot move() the window because it is outside our rect, then don't bail, just don't display it -- DONE;prio-10;cost-5;BUG
