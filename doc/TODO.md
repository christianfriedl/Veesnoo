* TextBox: size should be obvious when not focused, v.1 -- DONE;prio-1
* Window: seems to initially print all widgets twice... -- BUG;DONE;prio-1
* Textbox: needs to look differently when in edit mode -- DONE;prio-1
* Correctly set the cursor -- BUG;TODO;prio-1
* rename all members to have trailing \_s.
* Implement additional TextBox features -- TODO;prio-1;see todo-notes.txt
* Correctly test for location of curses.h header file -- DONE;prio-1
* Add configure/autoconf tests -- TODO;prio-1
* PopupMenu: figure out how to privatize cons but call it from create() -- TODO;prio-1
* #inlcude system header files from only one location -- TODO;prio-1
* Implement MainLoop -- TODO;prio-1
* Implement Horizontal Menu -- DONE;prio-1
* Implement Vertical Menu -- DONE;prio-1
* Implement Popup Menu -- DONE;prio-1
* Implement Message Box -- TODO;prio-1
* Implement Confirm Box -- TODO;prio-1
* Implement Select Box -- TODO;prio-1
* Implement Combo Box -- TODO;prio-1
* Implement Radio Button -- TODO;prio-1
* Implement Radio Group -- TODO;prio-1
* Implement Text area -- TODO;prio-1
* Checkbox: add constructor with frame -- TODO;prio-2
* Consider whether curses functions in curseswindow should run through cursesmanager -- TODO;prio-2
* Add scrolling containers -- TODO;prio-2
* CursesManager: rename getInstance() to get() -- TODO;prio-2;cost-5
* CursesManager: add public move cons -- TODO;prio-2;cost-8
* Implement Focus management -- TODO;prio-2
* Consistently use scoped enums -- TODO;prio-2
* Consistently "=default" or "=delete" or create special functions -- TODO;prio-2
* Add events -- TODO;prio-2
* Implement Window -- TODO;prio-2
* Implement App with basic loop (AppWindow??? MainWindow??) -- TODO;prio-2
* Reflect the basic class hierarchy -- TODO;prio-2;see-notes
* Implement multi-level undo -- TODO;prio-3
* Window needs to react to move(); -- TODO;prio-1
* All widgets need to react to move(); -- TODO;prio-1
* Figure out additional necessary widgets - see gtk for inspiration ( https://developer.gnome.org/gtk3/stable/ch03.html ) -- TODO;ongoing
* TextBox: size should be obvious when not focused, v.2 -- TODO;prio-4
* TextBox: add colors? (at what point?) -- TODO;prio-4
* TextBox: ... implement color pairs -- TODO;prio-4
* Add flexible keyboard interface -- TODO;prio-4
* Add flexible Color management -- TODO;prio-4
* Add sizing and layouting -- TODO;prio-4
* The whole bloody thing needs to be utf-8 -- TODO;prio-4
* Work with actual models -- TODO;prio-4
* Add validators -- TODO;prio-4
* Check out thread safety -- REFLECT;prio-4
* Add an xml ui description language -- REFLECT;prio-4
* Think about real life applications -- REFLECT;prio-5
* Add scriptability -- REFLECT;prio-6
* in src/, redo test/NONEXISTANT will try to redo test/NONEXISTANT.cc, then test/NONEXISTANT.cc.o, then test/NONEXISTANT.cc.o.cc, and so on -- BUG;TODO;prio-6
