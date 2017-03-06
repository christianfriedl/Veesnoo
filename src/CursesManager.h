#ifndef NV_CURSES_MANAGER_H
#define NV_CURSES_MANAGER_H

#include "NVBase.h"
#include "Rect.h"

namespace nv {

    class CursesManager {
        public:
            static CursesManager& get();
            
            WINDOW *createWindow(int x ,int y ,int width ,int height);
            void destroyWindow(WINDOW *window);
            void refresh();
            Rect getMaxScreenRect();
            int colorPair(int fg, int bg);
            int getCh();
            const char * const getKeyName(int ch) const;
        private:
            void initCurses();
            CursesManager(); 
            ~CursesManager();

            CursesManager(const CursesManager&);
            CursesManager& operator=(const CursesManager&);

            bool bufferedMode_;
            bool cBreak_;
            bool echo_;
            bool keypadAvailable_;
            int width_, height_;
            int nextPair_;
    };

}

#endif
