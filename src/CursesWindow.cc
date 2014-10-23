#include <algorithm>
#include "CursesWindow.h"
#include "CursesException.h"

namespace nv {

CursesWindow::CursesWindow(const Rect& rect) {
    window = CursesManager::getInstance().createWindow(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
}

CursesWindow::~CursesWindow() {
    CursesManager::getInstance().destroyWindow(window);
}

void CursesWindow::addString(const std::string& text) {
    int x, y;

    getyx(window, y, x);

    addString(text, x, y);
}

void CursesWindow::addString(const std::string& text, int x, int y) {
    int width, height;

    getmaxyx(window, height, width);
    mvwaddnstr(window, y, x, text.c_str(), std::min((int)text.length(), (int)(width - x)));
}

void CursesWindow::addCh(int ch) {
    int x, y;

    getyx(window, y, x);
    addCh(ch, x, y);
}

void CursesWindow::addCh(int ch, int x, int y) {
    mvwaddch(window, y, x, ch);
    wnoutrefresh(window);
}

void CursesWindow::refresh() {
    CursesManager::getInstance().refresh();
    wrefresh(window);
}

void CursesWindow::addBorder() {
    box(window, 0, 0);
    wnoutrefresh(window);
    CursesManager::getInstance().refresh();
}

int CursesWindow::getWidth() {
    int width, height;

    getmaxyx(window, height, width);
    return width;
}

int CursesWindow::getHeight() {
    int width, height;

    getmaxyx(window, height, width);
    return height;
}

void CursesWindow::attrOn(int attr) {
    wattron(window, attr);
}

void CursesWindow::attrOff(int attr) {
    wattroff(window, attr);
}

void CursesWindow::resize(int width, int height) {
    if ((wresize(window, height, width)) != OK)
        throw new Exception("unable to resize window");
}

void CursesWindow::moveCursor(int x, int y) {
    wmove(window, y, x);
}

void CursesWindow::move(int x, int y) {
    if ((mvwin(window, y, x)) != OK) {
        // [Logger logText: [NSString stringWithFormat: @"unable to move window %ld to x=%i, y=%i", window, x, y]];
        throw CursesException("unable to move window");
    }
}

void CursesWindow::fillBackground(int ch) {
    int x, y, maxx, maxy;
    getmaxyx(window, maxy, maxx);
    for (y = 0; y < maxy; ++y)
        for (x = 0; x < maxx; ++x)
            addCh(ch, x, y);
}

void CursesWindow::pairOn(int pair) {
    wattron(window, COLOR_PAIR(pair));
}

void CursesWindow::pairOff(int pair) {
    wattroff(window, COLOR_PAIR(pair));
}

void CursesWindow::resetColors() {
    wattrset(window, 0);
}

void CursesWindow::setCursorPosition(const int x, const int y) {
    if ( wmove(window, y, x) != OK )
        throw CursesException("unable to set cursor");
}

}
