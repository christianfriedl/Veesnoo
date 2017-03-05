#include <algorithm>
#include "Logger.h"
#include "CursesWindow.h"
#include "CursesException.h"

namespace nv {

    CursesWindow::CursesWindow(const Rect& rect) {
        window = CursesManager::getInstance().createWindow(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
        Logger::get().log("new CursesWindow from rect @ %llx (x: %i, y: %i, window: %llx)", this, rect.getX(), rect.getY(), window);
    }

    CursesWindow::~CursesWindow() {
        Logger::get().log("~ CursesWindow @ %llx (window: %llx)", this, window);
        CursesManager::getInstance().destroyWindow(window);
    }

    void CursesWindow::addString(const std::string& text) {
        Logger::get().log("CursesWindow(%llx)::addSring('%s'), (window %llx)", text.c_str(), window);
        int x, y;

        getyx(window, y, x);

        addString(text, x, y);
    }

    void CursesWindow::addString(const std::string& text, int x, int y) {
        Logger::get().log("CursesWindow(%llx)::addString('%s', %i, %i), window %llx", this, text.c_str(), x, y, window);
        int width, height;

        getmaxyx(window, height, width);
        auto actualLength = std::min((int)text.length(), (int)(width - x));
        mvwaddnstr(window, y, x, text.c_str(), actualLength);
    }

    void CursesWindow::addCh(int ch) {
        Logger::get().log("CursesWindow(%llx)::addCh(%i), window %llx", this, ch, window);
        int x, y;

        getyx(window, y, x);
        addCh(ch, x, y);
    }

    void CursesWindow::addCh(int ch, int x, int y) {
        Logger::get().log("CursesWindow(%llx)::addCh(%i, %i, %i), window %llx", this, ch, x, y, window);
        mvwaddch(window, y, x, ch);
    }

    void CursesWindow::refresh() {
        Logger::get().log("CursesWindow(%llx)::refresh(), window %llx", this, window);
        CursesManager::getInstance().refresh();
        wrefresh(window);
    }

    void CursesWindow::addBorder() {
        Logger::get().log("CursesWindow(%llx)::addBorder(), window %llx", this, window);
        box(window, 0, 0);
    }

    int CursesWindow::getWidth() {
        Logger::get().log("CursesWindow(%llx)::getWidth(), window %llx", this, window);
        int width, height;

        getmaxyx(window, height, width);
        return width;
    }

    int CursesWindow::getHeight() {
        Logger::get().log("CursesWindow(%llx)::getHeight(), window %llx", this, window);
        int width, height;

        getmaxyx(window, height, width);
        return height;
    }

    void CursesWindow::attrOn(int attr) {
        Logger::get().log("CursesWindow(%llx)::attrOn(%i), window %llx", this, attr, window);
        wattron(window, attr);
    }

    void CursesWindow::attrOff(int attr) {
        Logger::get().log("CursesWindow(%llx)::attrOff(%i), window %llx", this, attr, window);
        wattroff(window, attr);
    }

    void CursesWindow::resize(int width, int height) {
        Logger::get().log("CursesWindow(%llx)::resize(%i, %i), window %llx", this, width, height, window);
        if ((wresize(window, height, width)) != OK)
            throw new Exception("unable to resize window");
    }

    void CursesWindow::move(int x, int y) {
        Logger::get().log("CursesWindow(%llx)::move(%i, %i), window %llx", this, x, y, window);
        if ((mvwin(window, y, x)) != OK) {
            throw CursesException("unable to move window");
        }
    }

    void CursesWindow::fillBackground(int ch) {
        Logger::get().log("CursesWindow(%llx)::fillBackground(%i), window %llx", this, ch, window);
        int x, y, maxx, maxy;
        getmaxyx(window, maxy, maxx);
        for (y = 0; y < maxy; ++y)
            for (x = 0; x < maxx; ++x)
                addCh(ch, x, y);
    }

    void CursesWindow::pairOn(int pair) {
        Logger::get().log("CursesWindow(%llx)::pairOn(%i), window %llx", this, pair, window);
        wattron(window, COLOR_PAIR(pair));
    }

    void CursesWindow::pairOff(int pair) {
        Logger::get().log("CursesWindow(%llx)::pairOff(%i), window %llx", this, pair, window);
        wattroff(window, COLOR_PAIR(pair));
    }

    void CursesWindow::resetColors() {
        Logger::get().log("CursesWindow(%llx)::resetColors(), window %llx", this);
        wattrset(window, 0);
    }

    void CursesWindow::setCursorPosition(const int x, const int y) {
        Logger::get().log("CursesWindow(%llx)::setCursorPosition(%i, %i), window %llx", this, x, y, window);
        if ( wmove(window, y, x) != OK )
            throw CursesException("unable to set cursor");
    }

}
