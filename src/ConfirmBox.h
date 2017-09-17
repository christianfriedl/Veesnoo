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


#ifndef NV_CONFIRM_BOX_H
#define NV_CONFIRM_BOX_H

#include "Window.h"
#include "Label.h"
#include "Button.h"
#include "BasicEvent.h"
#include "PopupWindow.h"

namespace nv {

    class ConfirmBox: public PopupWindow {
        public:
            ConfirmBox(const std::string& title, const std::string& text);
            virtual ~ConfirmBox();
            static const std::shared_ptr<ConfirmBox> create(const std::string& title, const std::string& text);
            const std::shared_ptr<Label> getLabel();
            void layout();
            virtual bool open() override;
            virtual bool close() override;
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onAfterClose;
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onOkPushed;
            sigc::signal<void, const std::shared_ptr<BasicEvent>&> onCancelPushed;

            virtual void refresh() override { LOGMETHODONLY(); PopupWindow::refresh(); } // just for debug
            virtual bool receiveKey(int ch) override { LOGMETHOD("%i", ch); return PopupWindow::receiveKey(ch); } // just for debug


        private:
            void okPushed(const std::shared_ptr<BasicEvent>& ev);
            void cancelPushed(const std::shared_ptr<BasicEvent>& ev);
            std::shared_ptr<Label> label_;
            std::shared_ptr<Button> okButton_;
            std::shared_ptr<Button> cancelButton_;
            std::string title_;
    };

}

#endif
