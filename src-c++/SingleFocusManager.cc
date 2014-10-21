#include "SingleFocusManager.h"

namespace nv {

void SingleFocusManager::setWidget(const Widget& widget) { widget_ = &widget; }

bool SingleFocusManager::receiveKey(int ch) {
    return false;
}

void SingleFocusManager::focus() {
    isFocused_ = true;
}

void SingleFocusManager::deFocus() {
    isFocused_ = false;
}

}
