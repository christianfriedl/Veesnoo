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


#include "MainLoop.h"

namespace veesnoo {

    MainLoop::MainLoop(std::shared_ptr<FocusableContainer> mainContainer): mainContainer_(mainContainer) {
    }

    void
    MainLoop::run() {
        mainContainer_->focus();

        int ch = 0; 
        bool received = false;
        do {
            mainContainer_->refresh();
            ch = CursesManager::get().getCh();
            received = mainContainer_->receiveKey(ch);
        } while ( received );
    }

    std::shared_ptr<FocusableContainer>& MainLoop::getContainer() {
        return mainContainer_;
    }
}
