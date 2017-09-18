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
#include "MessageBox.h"

namespace veesnoo {

    MessageBox::MessageBox(const std::string& title, const std::string& text): Window(Rect(0, 0, 1, 1), title) {
        label_ = std::make_shared<Label>(text, 1, 1);
    }

    MessageBox::~MessageBox() {}

    const std::shared_ptr<MessageBox> MessageBox::create(const std::string& title, const std::string& text) {
        auto mb = std::make_shared<MessageBox>(title, text);
        mb->addWidget(mb->getLabel());
        mb->layout();
        return mb;
    }

    const std::shared_ptr<Label> MessageBox::getLabel() {
        return label_;
    }

    void MessageBox::layout() {
        int maxTextLen = std::max(title_.length(), (unsigned long)label_->getRect().getWidth()); // TODO utf8-ize
        resize(maxTextLen + 5, 8); // TODO whatevs
        int labelX = std::max(rect_.getWidth() / 2 - maxTextLen / 2 - 1, 0);
        int labelY = std::max(rect_.getHeight() / 2 - 1, 0);
        label_->move(labelX, labelY);
        Logger::get().log("MB2 contentRect_ %s", contentRect_.toString()->c_str());
        if ( parent_.use_count() != 0 ) { // we have a parent
            auto parent = parent_.lock();
            if ( parent == nullptr )
                throw std::runtime_error("Parent found, but not accessible.");
            int x = std::max(parent->getContentRect().getWidth() / 2 - rect_.getWidth() / 2, 0);
            int y = std::max(parent->getContentRect().getHeight() / 2 - rect_.getHeight() / 2, 0);
            move(x, y);
        }
    }

    /** regardless of what happens, we will just close the box */
    bool MessageBox::receiveKey(int ch) {
        LOGMETHOD("%i", ch);
        if ( parent_.use_count() != 0 ) { // we have a parent
            auto parent = std::static_pointer_cast<Container>(parent_.lock()); // GNARF!
            if ( parent == nullptr )
                throw std::runtime_error("Parent found, but not accessible.");
            parent->removeWidget(shared_from_this());
            auto ev(std::make_shared<BasicEvent>(shared_from_this()));
            onAfterClose.emit(ev);
        }
        return true;
    }

}
