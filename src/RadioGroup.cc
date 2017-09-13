#include "RadioGroup.h"

namespace nv {

    void RadioGroup::addButton(std::shared_ptr<RadioButton> button) {
        buttons_.emplace_back(button);
        button->onAfterChange.connect( sigc::mem_fun(*this, &RadioGroup::buttonChanged) );
    }

    void RadioGroup::buttonChanged(const std::shared_ptr<ChangeEvent>& ev) {
        for ( auto button: buttons_ )
            if ( button != ev->getTarget() )
                button->setChecked(false);
    }

}
