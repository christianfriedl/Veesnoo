#include "SingleFocusManager.h"

namespace nv {


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
