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


#ifndef NV_CONTAINER_H
#define NV_CONTAINER_H

#include <memory>
#include <vector>
#include "Widget.h"
#include "Logger.h"

namespace veesnoo {

class Container: public Widget {
public:
    explicit Container(const Rect& rect): Widget(rect), subWidgets_() {
        LOGMETHODONLY();
    }
    static std::shared_ptr<Container> create(const Rect& rect);
    virtual ~Container() {
        // TODO: Will we delete the subWidgets_, or will we set teir parent to null? currently, they will be deleted along wit us
        LOGMETHODONLY();
    }
    virtual void addWidget(const std::shared_ptr<Widget>& widget);
    virtual void removeWidget(const std::shared_ptr<Widget>& widget);
    auto getSubWidgets() const { return subWidgets_; } // we copy the vector, because in all likelihood this will be like 10 pointers or so
    int getSubWidgetsSize() const { return subWidgets_.size(); }
    void refresh() override;
    
protected:
    std::vector<std::shared_ptr<Widget> > subWidgets_;
};

}

#endif
