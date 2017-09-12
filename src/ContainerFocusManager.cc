#include<algorithm>
#include"Logger.h"
#include "ContainerFocusManager.h"
#include "FocusableContainer.h"
#include "FocusableWidget.h"

namespace nv {

ContainerFocusManager::ContainerFocusManager(FocusableContainer *widget) : 
        widget_(widget), focusedWidget_(nullptr), isFocused_(false) {
            LOGMETHOD("widget = %llx", widget);
}

std::shared_ptr<Focusable> 
ContainerFocusManager::getFocusedWidget() {
    return focusedWidget_;
}


bool ContainerFocusManager::bubbleReceiveKey(int ch, std::shared_ptr<Widget> w) {
    LOGMETHOD("%i", ch);
    auto f = std::dynamic_pointer_cast<Focusable> (w);

    if ( !f ) throw Exception("w is not focusable");

    Logger::get().log("ContainerFocusManager(%llx)::bubbleReceiveKey: we are before the if", this);
    if ( f.get() == dynamic_cast<Focusable*>(widget_) ) { // the widget we are requested to bubble to is our own widget
        Logger::get().log("ContainerFocusManager(%llx)::bubbleReceiveKey will return false", this);
        LOGMETHOD("will return false", "");
        return false;
    } else if ( f->receiveKey(ch) ) {
        Logger::get().log("ContainerFocusManager(%llx)::bubbleReceiveKey will return true", this);
        LOGMETHOD("will return true", "");
        return true;
    } else {
        auto ff = w->getParent().lock();
        Logger::get().log("ContainerFocusManager(%llx)::bubbleReceiveKey no parent found, will return false", this);
        LOGMETHOD("no parent found, will return false", "");
        if ( !ff )
            return false;
        LOGMETHOD("will bubbleReceiveKey(%i, %llx)", ch, ff.get());
        return bubbleReceiveKey(ch, ff);
    }
    Logger::get().log("ContainerFocusManager(%llx)::bubbleReceiveKey: we are after the if", this);
}

bool ContainerFocusManager::receiveKey(int ch) {
    LOGMETHOD("%i", ch);
    auto fw = focusedWidget_; // we already have a focusedWidget_, therefore we need to try bubbling the event
    if ( fw )  {
        LOGMETHOD("will bubbleReceiveKey(%i, %llx)", ch, fw.get());
        if ( bubbleReceiveKey(ch, std::dynamic_pointer_cast<Widget>(fw)) )
            return true;
    } else {
        LOGMETHOD("will focusFirst()", "");
        focusFirst();
        return true;
    }
        
    if (ch == ' ' || ch == '\t' || ch == KEY_STAB || ch == KEY_DOWN || ch == KEY_RIGHT || ch == 'j' || ch == 'l') {
        LOGMETHOD("will focusNext()", "");
        focusNext();
        return true;
    }
    else if (ch == KEY_BACKSPACE || ch == KEY_BTAB || ch == KEY_UP || ch == KEY_LEFT || ch == 'k' || ch == 'h') {
        LOGMETHOD("will focusPrev()", "");
        focusPrev();
        return true;
    }
    else {
        LOGMETHOD("will return false", "");
        return false;
    }
}

void ContainerFocusManager::focus() {
    LOGMETHODONLY();
    isFocused_ = true;
    focusFirst();
}

void ContainerFocusManager::blur() {
    LOGMETHODONLY();
    isFocused_ = false;
}
std::vector<std::shared_ptr<Widget>> 
ContainerFocusManager::getSubWidgets() {
    return widget_->getSubWidgets();
}


std::vector<std::shared_ptr<Focusable>> ContainerFocusManager::getFocusableSubWidgets() {
    auto subWidgets = getSubWidgets();
    auto focusableSubWidgets = std::vector<std::shared_ptr<Focusable>>();

    for ( auto widget: subWidgets ) {
        if ( widget->getIsVisibleBubbling() ) {
            auto f = std::dynamic_pointer_cast<Focusable>(widget);
            if ( f.get() != nullptr )
                focusableSubWidgets.emplace_back(f);
        }
    }

    return focusableSubWidgets;
}

void ContainerFocusManager::focusFirst() {
    LOGMETHODONLY();
    auto focusableSubWidgets = getFocusableSubWidgets();

    if ( focusableSubWidgets.size() != 0 ) {
        LOGMETHOD("will focus %llx", focusableSubWidgets.front().get());
        focusThis(focusableSubWidgets.front());
    }
}

void ContainerFocusManager::focusNext() {
    LOGMETHODONLY();
    auto focusableSubWidgets = getFocusableSubWidgets();
        
    if (focusableSubWidgets.size() != 0) {
        std::shared_ptr<Focusable> res;
        unsigned long i=0;

        for (auto widget : focusableSubWidgets) {
            if (widget.get() == focusedWidget_.get()) {
                if (i == focusableSubWidgets.size() - 1)
                    res = focusableSubWidgets[0];
                else
                    res = focusableSubWidgets[i+1];
                break;
            } 
            ++i;
        }
        if (res) {
            LOGMETHOD("coming from %llx, i have next focusable=%llx", focusedWidget_.get(), res.get());
            focusThis(res);
        } else {
            LOGMETHOD("coming from %llx, i have no next focusable", focusedWidget_.get());
        }
    }
}

void ContainerFocusManager::focusPrev() {
    auto focusableSubWidgets = getFocusableSubWidgets();

    if (focusableSubWidgets.size() != 0) {
        std::shared_ptr<Focusable> res;
        int i = focusableSubWidgets.size() - 1;
        for (std::vector<std::shared_ptr<Focusable> >::reverse_iterator iter = focusableSubWidgets.rbegin(); 
                iter != focusableSubWidgets.rend(); ++iter) {
            if ((*iter) == focusedWidget_) {
                if (i == 0)
                    res = focusableSubWidgets[focusableSubWidgets.size() - 1];
                else
                    res = focusableSubWidgets[i-1];
                break;
            } 
            --i;
        }
        if ( res ) {
            LOGMETHOD("will focus %llx", res.get());
            focusThis(res);
        }
    }
}

void ContainerFocusManager::focusThis(std::shared_ptr<Focusable>& widget) {
    LOGMETHOD("will focus %llx", widget.get());
    auto focusableSubWidgets = getFocusableSubWidgets();

    focusedWidget_ = widget;
    if ( widget->isFocused() ) {
        return;
    }
    for ( auto widget: focusableSubWidgets ) {
        if ( focusedWidget_.get() == widget.get() )
            widget->focus();
        else
            widget->blur();
    }
}

bool ContainerFocusManager::isFocused() const {
    LOGMETHOD("%i", isFocused_);
    return isFocused_;
}

/**
 * we are being requested to focus the widget
 */
void ContainerFocusManager::requestFocus(std::shared_ptr<Focusable> widget) {
    LOGMETHOD("will request focus for widget %llx", widget.get());
    if ( widget_->getParent().use_count() > 0 ) {
        std::shared_ptr<Widget> p = widget_->getParent().lock();
        if ( p ) {
            auto fcp = std::dynamic_pointer_cast<FocusableContainer>(p); // widget's parent as focusable container
            if ( !fcp )
                throw Exception("could not cast parent to FocusableContainer");
            fcp->requestFocus(widget); // ask widget's parent to request focus on this widget
            return;
        } else
            throw Exception("could not obtain parent lock");
    } 
    focusedWidget_ = widget;
}

}
