#ifndef NV_SCROLLPANE_H
#define NV_SCROLLPANE_H

#include "FocusableContainer.h"
#include "Rect.h"

/*

            ->  scroll(2,0)
   +...+                   +...+
   |ab+---+                |a+---+
   |zy||  |                |z|x| |
   +..|+  |                +.|.+ |
      +---+                  +---+

*/

namespace nv {

    class ScrollPane: public FocusableContainer {
        public:
            ScrollPane(Rect rect); 
            void addString(const std::string& text); 
            void addString(const std::string& text, const int x, const int y); 
            void addStringUnscrolled(const std::string& text);
            void addStringUnscrolled(const std::string& text, const int x, const int y);
            void addCh(int ch);
            void addCh(const int ch, const int x, const int y); 
            void addChUnscrolled(const int ch);
            void addChUnscrolled(const int ch, const int x, const int y);
            void scrollBy(const int deltaX, const int deltaY);
            void scrollTo(const int x, const int y);

        private:
            Point viewPort_;
    };

}
#endif
