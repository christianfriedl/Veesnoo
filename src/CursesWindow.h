#ifndef NV_CURSES_WINDOW_H
#define NV_CURSES_WINDOW_H

#include "NVBase.h"
#include "CursesManager.h"

namespace nv {

    class CursesWindow {

        public:
            CursesWindow(const Rect& rect);
            ~CursesWindow();
            void addString(const std::string& text);
            void addString(const std::string& text, int x, int y);
            void addCh(int ch, int x, int y);
            void refresh();
            void addBorder();
            void addCh(int ch);
            int width();
            int height();
            void attrOn(int attr);
            void attrOff(int attr);
            void pairOn(int apair);
            void pairOff(int apair);
            void resetColors();
            void resize(int width, int height);
            void move(int x, int y);
            void fillBackground(int ch);
            int getWidth();
            int getHeight();
            void setCursorPosition(const int x, const int y);

            // just for testing
            WINDOW *getWin() { return window; }

        private:
            WINDOW *window;

    };

}

#endif
