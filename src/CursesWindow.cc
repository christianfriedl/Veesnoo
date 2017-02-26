#include <algorithm>
#include "Logger.h"
#include "CursesWindow.h"
#include "CursesException.h"

namespace nv {

#ifndef NV_NO_PAINTING

// normal, nondebugging mode

CursesWindow::CursesWindow(const Rect& rect) {
    window = CursesManager::getInstance().createWindow(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    Logger::get().log("new CursesWindow from rect @ %lld (x: %i, y: %i, window: %lld)", this, rect.getX(), rect.getY(), window);
}

/*
CursesWindow::CursesWindow(std::unique_ptr<const Rect> rect) {
    window = CursesManager::getInstance().createWindow(rect->getX(), rect->getY(), rect->getWidth(), rect->getHeight());
    Logger::get().log("new CursesWindow from up rect @ %lld (x: %i, y: %i, window: %lld)", this, rect->getX(), rect->getY(), window);
}
*/

CursesWindow::~CursesWindow() {
    Logger::get().log("~ CursesWindow @ %lld (window: %lld)", this, window);
    CursesManager::getInstance().destroyWindow(window);
}

void CursesWindow::addString(const std::string& text) {
    int x, y;

    getyx(window, y, x);
    Logger::get().log("CursesWindow addSring(text) adding text t: %s, %i %i", text.c_str(), x, y);

    addString(text, x, y);
}

void CursesWindow::addString(const std::string& text, int x, int y) {
    int width, height;

    getmaxyx(window, height, width);
    auto actualLength = std::min((int)text.length(), (int)(width - x));
    Logger::get().log("CursesWindow adding text: '%s', x %i y %i width %i height %i text.length %i, actualLength %i, window %lld", text.c_str(), x, y, width, height, (int)text.length(), actualLength, window);
    mvwaddnstr(window, y, x, text.c_str(), actualLength);
    wnoutrefresh(window);
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
        // [Logger logText: [NSString stringWithFormat: @"unable to move window %lld to x=%i, y=%i", window, x, y]];
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
#else

// debugging mode

CursesWindow::CursesWindow(const Rect& rect) {
    window = nullptr;
    Logger::get().log("new CursesWindow from rect @ %lld (x: %i, y: %i, no curses window)", this, rect.getX(), rect.getY());
}

CursesWindow::~CursesWindow() {
    Logger::get().log("~ CursesWindow without curses window)", this);
}

void CursesWindow::addString(const std::string& text) {
}

void CursesWindow::addString(const std::string& text, int x, int y) {
}

void CursesWindow::addCh(int ch) {
}

void CursesWindow::addCh(int ch, int x, int y) {
}

void CursesWindow::refresh() {
}

void CursesWindow::addBorder() {
}

int CursesWindow::getWidth() {
    return 0;
}

int CursesWindow::getHeight() {
    return 0;
}

void CursesWindow::attrOn(int attr) {
}

void CursesWindow::attrOff(int attr) {
}

void CursesWindow::resize(int width, int height) {
}

void CursesWindow::moveCursor(int x, int y) {
}

void CursesWindow::move(int x, int y) {
}

void CursesWindow::fillBackground(int ch) {
}

void CursesWindow::pairOn(int pair) {
}

void CursesWindow::pairOff(int pair) {
}

void CursesWindow::resetColors() {
}

void CursesWindow::setCursorPosition(const int x, const int y) {
}

#endif

}
