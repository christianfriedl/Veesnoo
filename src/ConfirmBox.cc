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


#include "Logger.h"
#include "ConfirmBox.h"

namespace nv {

    ConfirmBox::ConfirmBox(const std::string& title, const std::string& text): Window(Rect(0, 0, 1, 1), title) {
        label_ = std::make_shared<Label>(text, 1, 1);
        okButton_ = std::make_shared<Button>("Ok", 1, 1);
        okButton_->onAfterPush.connect( sigc::mem_fun(this, &ConfirmBox::okPushed) );
        cancelButton_ = std::make_shared<Button>("Cancel", 1, 1);
        cancelButton_->onAfterPush.connect( sigc::mem_fun(this, &ConfirmBox::cancelPushed) );
    }

    ConfirmBox::~ConfirmBox() {}

    const std::shared_ptr<ConfirmBox> ConfirmBox::create(const std::string& title, const std::string& text) {
        auto mb = std::make_shared<ConfirmBox>(title, text);
        mb->addWidget(mb->label_);
        mb->addWidget(mb->okButton_);
        mb->addWidget(mb->cancelButton_);
        mb->layout();
        return mb;
    }

    const std::shared_ptr<Label> ConfirmBox::getLabel() {
        return label_;
    }

    void ConfirmBox::layout() {
        int maxTextLen = std::max(title_.length(), (unsigned long)label_->getRect().getWidth()); // TODO utf8-ize
        resize(maxTextLen + 20, 8); // TODO whatevs
        int labelX = std::max(rect_.getWidth() / 2 - maxTextLen / 2 - 1, 0);
        int labelY = std::max(rect_.getHeight() / 2 - 1, 0);
        label_->move(labelX, labelY);
        int okButtonX = 2;
        int okButtonY = std::max(rect_.getHeight() / 2 + 1, 0);
        okButton_->move(okButtonX, okButtonY);
        int cancelButtonX = std::max(rect_.getWidth() - 2 - 12, okButton_->getRect().getWidth() + okButtonX + 2);
        int cancelButtonY = std::max(rect_.getHeight() / 2 + 1, 0);
        cancelButton_->move(cancelButtonX, cancelButtonY);
        if ( parent_.use_count() != 0 ) { // we have a parent
            auto parent = parent_.lock();
            if ( parent == nullptr )
                throw std::runtime_error("Parent found, but not accessible.");
            int x = std::max(parent->getContentRect().getWidth() / 2 - rect_.getWidth() / 2, 0);
            int y = std::max(parent->getContentRect().getHeight() / 2 - rect_.getHeight() / 2, 0);
            move(x, y);
        }
    }

    bool ConfirmBox::open() {
        if ( !FocusStealer::open() )
            return false;
        show();
    }
    bool ConfirmBox::close() {
        Logger::get().log("ConfirmBox(%llx)::close()", this);
        if ( !FocusStealer::close() )
            return false;
        hide();
        auto ev(std::make_shared<BasicEvent>(shared_from_this()));
        onAfterClose.emit(ev);
        return true;
    }

    void ConfirmBox::okPushed(const std::shared_ptr<BasicEvent>& ev) {
        Logger::get().log("ConfirmBox(%llx)::okPushed()", this);
        auto ev2(std::make_shared<BasicEvent>(shared_from_this()));
        onOkPushed.emit(ev2);
        close();
    }

    void ConfirmBox::cancelPushed(const std::shared_ptr<BasicEvent>& ev) {
        Logger::get().log("ConfirmBox(%llx)::cancelPushed()", this);
        auto ev2(std::make_shared<BasicEvent>(shared_from_this()));
        onCancelPushed.emit(ev2);
        close();
    }

}
