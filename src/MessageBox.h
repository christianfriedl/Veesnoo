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


#ifndef NV_VERTICAL_MENU_H
#define NV_VERTICAL_MENU_H

#include "Window.h"
#include "Label.h"
#include "BasicEvent.h"

namespace veesnoo {

    class MessageBox: public Window {
        public:
            MessageBox(const std::string& title, const std::string& text);
            virtual ~MessageBox();
            static const std::shared_ptr<MessageBox> create(const std::string& title, const std::string& text);

            const std::shared_ptr<Label> getLabel();
            void layout();
            bool receiveKey(int ch) override;
            void refresh() override { LOGMETHODONLY(); Window::refresh(); } // just for debug
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterClose;

        private:
            std::shared_ptr<Label> label_;
            std::string title_;
    };

}

#endif
