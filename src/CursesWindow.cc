/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Veesnoo is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#include <algorithm>
#include "Logger.h"
#include "CursesWindow.h"
#include "CursesException.h"
#include "ColorAttribute.h"

namespace veesnoo {

    CursesWindow::CursesWindow(const Rect& rect) {
        window_ = CursesManager::get().createWindow(rect.getX(), rect.getY(), rect.getWidth(), rect.getHeight());
    }

    CursesWindow::~CursesWindow() {
        CursesManager::get().destroyWindow(window_);
    }

    void CursesWindow::addString(const std::string& text) {
        LOGMETHOD("%llx, %s", window_, text.c_str());
        int x, y;

        getyx(window_, y, x);

        addString(text, x, y);
    }

    void CursesWindow::addString(const std::string& text, int x, int y) {
        LOGMETHOD("%llx, %s, %i, %i", window_, text.c_str(), x, y);
        int width, height; // warning can be ignored, height is dummy for curses interface

        getmaxyx(window_, height, width);
        auto actualLength = std::min((int)text.length(), (int)(width - x));
        mvwaddnstr(window_, y, x, text.c_str(), actualLength);
    }

    void CursesWindow::addCh(int ch) {
        LOGMETHOD("%llx, %i", window_, ch);
        int x, y;

        getyx(window_, y, x);
        addCh(ch, x, y);
    }

    void CursesWindow::addCh(int ch, int x, int y) {
        LOGMETHOD("%llx, %i, %i, %i", window_, ch, x, y);
        mvwaddch(window_, y, x, ch);
    }

    void CursesWindow::refresh() {
        LOGMETHOD("window_ %llx", window_);
        wrefresh(window_);
    }

    void CursesWindow::noutrefresh() {
        LOGMETHOD("window_ %llx", window_);
        ::wnoutrefresh(window_);
    }

    void CursesWindow::addBorder() {
        LOGMETHOD("%llx", window_);
        box(window_, 0, 0);
    }

    int CursesWindow::getWidth() {
        LOGMETHOD("%llx", window_);
        int width, height; // warning can be ignored, height is dummy for curses interface

        getmaxyx(window_, height, width);
        return width;
    }

    int CursesWindow::getHeight() {
        LOGMETHOD("%llx", window_);
        int width, height;

        getmaxyx(window_, height, width);
        return height;
    }

    void CursesWindow::attrOn(int attr) {
        LOGMETHOD("%llx %i", window_, attr);
        wattron(window_, attr);
    }

    void CursesWindow::attrOff(int attr) {
        LOGMETHOD("%llx %i", window_, attr);
        wattroff(window_, attr);
    }

    void CursesWindow::resize(int width, int height) {
        LOGMETHOD("%llx %i, %i", window_, width, height);
        if ((wresize(window_, height, width)) != OK)
            throw new Exception("unable to resize window_");
    }

    void CursesWindow::move(int x, int y) {
        LOGMETHOD("%llx %i, %i", window_, x, y);
        if ((mvwin(window_, y, x)) != OK) {
            throw CursesException("unable to move window_");
        }
    }

    void CursesWindow::fillBackground(int ch) {
        LOGMETHOD("%llx %i", window_, ch);
        int x, y, maxx, maxy;
        getmaxyx(window_, maxy, maxx);
        for (y = 0; y < maxy; ++y)
            for (x = 0; x < maxx; ++x)
                addCh(ch, x, y);
    }

    void CursesWindow::pairOn(int pair) {
        LOGMETHOD("%llx %i", window_, pair);
        wattron(window_, COLOR_PAIR(pair));
    }

    void CursesWindow::pairOff(int pair) {
        LOGMETHOD("%llx %i", window_, pair);
        wattroff(window_, COLOR_PAIR(pair));
    }

    void CursesWindow::resetColors() {
        LOGMETHOD("%llx", window_);
        wattrset(window_, 0);
    }

    void CursesWindow::setCursorPosition(const int x, const int y) {
        LOGMETHOD("%llx %i, %i", window_, x, y);
        if ( wmove(window_, y, x) != OK )
            throw CursesException("unable to set cursor");
    }

    int CursesWindow::getCursAttr(const ColorAttribute& attribute) {
        int cursAttr = COLOR_PAIR(attribute.getPairNumber());
        if ( attribute.getInverse() )
            cursAttr |= A_REVERSE;
        if ( attribute.getBold() )
            cursAttr |= A_BOLD;
        if ( attribute.getUnderline() )
            cursAttr |= A_UNDERLINE;
        if ( attribute.getBlink() )
            cursAttr |= A_BLINK;
        return cursAttr;
    }
    void CursesWindow::startColorAttribute(const ColorAttribute& attribute) {
        LOGMETHOD("%llx %s", window_, attribute.toString().c_str());
        wattron(window_, getCursAttr(attribute));
    }
    void CursesWindow::endColorAttribute(const ColorAttribute& attribute) {
        LOGMETHOD("%llx %s", window_, attribute.toString().c_str());
        wattroff(window_, getCursAttr(attribute));
    }

}
