/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
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
        Logger::get().log("new CursesWindow from rect @ %llx (x: %i, y: %i, window_: %llx)", this, rect.getX(), rect.getY(), window_);
    }

    CursesWindow::~CursesWindow() {
        Logger::get().log("~ CursesWindow @ %llx (window_: %llx)", this, window_);
        CursesManager::get().destroyWindow(window_);
    }

    void CursesWindow::addString(const std::string& text) {
        Logger::get().log("CursesWindow(%llx)::addSring('%s'), (window_ %llx)", text.c_str(), window_);
        int x, y;

        getyx(window_, y, x);

        addString(text, x, y);
    }

    void CursesWindow::addString(const std::string& text, int x, int y) {
        Logger::get().log("CursesWindow(%llx)::addString('%s', %i, %i), window_ %llx", this, text.c_str(), x, y, window_);
        int width, height; // warning can be ignored, height is dummy for curses interface

        getmaxyx(window_, height, width);
        auto actualLength = std::min((int)text.length(), (int)(width - x));
        mvwaddnstr(window_, y, x, text.c_str(), actualLength);
    }

    void CursesWindow::addCh(int ch) {
        Logger::get().log("CursesWindow(%llx)::addCh(%i), window_ %llx", this, ch, window_);
        int x, y;

        getyx(window_, y, x);
        addCh(ch, x, y);
    }

    void CursesWindow::addCh(int ch, int x, int y) {
        Logger::get().log("CursesWindow(%llx)::addCh(%i, %i, %i), window_ %llx", this, ch, x, y, window_);
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
        Logger::get().log("CursesWindow(%llx)::addBorder(), window_ %llx", this, window_);
        box(window_, 0, 0);
    }

    int CursesWindow::getWidth() {
        Logger::get().log("CursesWindow(%llx)::getWidth(), window_ %llx", this, window_);
        int width, height; // warning can be ignored, height is dummy for curses interface

        getmaxyx(window_, height, width);
        return width;
    }

    int CursesWindow::getHeight() {
        Logger::get().log("CursesWindow(%llx)::getHeight(), window_ %llx", this, window_);
        int width, height;

        getmaxyx(window_, height, width);
        return height;
    }

    void CursesWindow::attrOn(int attr) {
        Logger::get().log("CursesWindow(%llx)::attrOn(%i), window_ %llx", this, attr, window_);
        wattron(window_, attr);
    }

    void CursesWindow::attrOff(int attr) {
        Logger::get().log("CursesWindow(%llx)::attrOff(%i), window_ %llx", this, attr, window_);
        wattroff(window_, attr);
    }

    void CursesWindow::resize(int width, int height) {
        Logger::get().log("CursesWindow(%llx)::resize(%i, %i), window_ %llx", this, width, height, window_);
        if ((wresize(window_, height, width)) != OK)
            throw new Exception("unable to resize window_");
    }

    void CursesWindow::move(int x, int y) {
        Logger::get().log("CursesWindow(%llx)::move(%i, %i), window_ %llx", this, x, y, window_);
        if ((mvwin(window_, y, x)) != OK) {
            throw CursesException("unable to move window_");
        }
    }

    void CursesWindow::fillBackground(int ch) {
        Logger::get().log("CursesWindow(%llx)::fillBackground(%i), window_ %llx", this, ch, window_);
        int x, y, maxx, maxy;
        getmaxyx(window_, maxy, maxx);
        for (y = 0; y < maxy; ++y)
            for (x = 0; x < maxx; ++x)
                addCh(ch, x, y);
    }

    void CursesWindow::pairOn(int pair) {
        Logger::get().log("CursesWindow(%llx)::pairOn(%i), window_ %llx", this, pair, window_);
        wattron(window_, COLOR_PAIR(pair));
    }

    void CursesWindow::pairOff(int pair) {
        Logger::get().log("CursesWindow(%llx)::pairOff(%i), window_ %llx", this, pair, window_);
        wattroff(window_, COLOR_PAIR(pair));
    }

    void CursesWindow::resetColors() {
        Logger::get().log("CursesWindow(%llx)::resetColors(), window_ %llx", this);
        wattrset(window_, 0);
    }

    void CursesWindow::setCursorPosition(const int x, const int y) {
        Logger::get().log("CursesWindow(%llx)::setCursorPosition(%i, %i), window_ %llx", this, x, y, window_);
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
        LOGMETHOD("will start color pair %s", attribute.toString().c_str());

        wattron(window_, getCursAttr(attribute));
    }
    void CursesWindow::endColorAttribute(const ColorAttribute& attribute) {
        LOGMETHOD("will end color pair %s", attribute.toString().c_str());
        wattroff(window_, getCursAttr(attribute));
    }

    void CursesWindow::startColorAttribute(std::shared_ptr<ColorAttribute> attribute) {
        auto attr = attribute.get();
        startColorAttribute(*attr);
    }
    void CursesWindow::endColorAttribute(std::shared_ptr<ColorAttribute> attribute) {
        auto attr = attribute.get();
        endColorAttribute(*attr);
    }

}
