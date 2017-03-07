#include "nvwm.h"

using namespace nv;

int main() {
    auto widget = std::make_shared<Widget>(Rect(0, 0, 0, 0));
    ChangeEvent changeEvent(widget);
}
