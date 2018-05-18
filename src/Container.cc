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
#include "Container.h"
#include "Logger.h"

namespace veesnoo {
    std::shared_ptr<Container> 
    Container::create(const Rect& rect) {
        return std::make_shared<Container>(rect);
    }

    void Container::addWidget(const std::shared_ptr<Widget>& widget) {
        auto weakThis = std::weak_ptr<Widget>(shared_from_this());
        widget->setParent(weakThis);
        subWidgets_.emplace_back(widget);
    }

    void Container::removeWidget(const std::shared_ptr<Widget>& widget) {
        subWidgets_.erase(std::remove(subWidgets_.begin(), subWidgets_.end(), widget));
    }


    void Container::refresh() {
        LOGMETHODONLY();
        if ( !getIsVisibleBubbling() )
            return;
        fillBackground(' ', getContentColorAttribute());
        addContent();
        setCWPosition(getAbsoluteRect()); // TODO check if still valid: not necessary until we have a working move(), but what the bloody heck
        cursesWindow_->noutrefresh();
        for ( auto widget: subWidgets_ ) {
            widget->refresh();
        }
        if ( parent_.use_count() == 0 )
            CursesManager::get().refresh();
    }

}
