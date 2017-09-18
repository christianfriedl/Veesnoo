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


#ifndef NV_CONTAINER_FOCUS_MANAGER_H
#define NV_CONTAINER_FOCUS_MANAGER_H

#include <vector>
#include "Widget.h"
#include "Focusable.h"
#include "FocusableWidget.h"

namespace veesnoo {

class FocusableContainer;

class ContainerFocusManager { 

public:
    explicit ContainerFocusManager(FocusableContainer *widget);
    virtual ~ContainerFocusManager() {}

    void setWidget(FocusableContainer *widget) { widget_ = widget; }

    bool receiveKey(int ch);
    void focus();
    void blur();
    void focusFirst();
    void focusNext();
    void focusPrev();
    bool isFocused() const;
    void focusThis(std::shared_ptr<Focusable>& widget); // focus this direct subwidget of ours
    void requestFocus(std::shared_ptr<Focusable> widget); // subwidget, or sub-subwidget, wants the focus
    void requestFocus(FocusableContainer *widget);
    std::shared_ptr<Focusable> getFocusedWidget();

private:
    std::vector<std::shared_ptr<Widget>> getSubWidgets();
    std::vector<std::shared_ptr<Focusable>> getFocusableSubWidgets();
    bool bubbleReceiveKey(int ch, std::shared_ptr<Widget> w);
    void bubbleFocusNext();
    void bubbleFocusPrev();
    bool getIsFocusStealing();
    std::vector<std::shared_ptr<Focusable>> getFocusableSubWidgetsOrdered();

    FocusableContainer *widget_;
    std::shared_ptr<Focusable> focusedWidget_;
    bool isFocused_;
    // std::vector<std::shared_ptr<Focusable>>(tmpSubWidgets.size()) focusableSubWidgets_; // only ever used temporarily

};

}

#endif
