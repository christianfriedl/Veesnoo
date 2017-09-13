#include <vector>
#include "ChangeEvent.h"
#include "RadioButton.h"

namespace nv {

    /**
     * basic RadioGroup.
     *
     * this is not a widget, nor a container, it is just a managing entity
     * to change all buttons in the group to unchecked if one is checked
     */
    class RadioGroup {
        public:
            void addButton(std::shared_ptr<RadioButton> button);
            void buttonChanged(const std::shared_ptr<ChangeEvent>& ev);
                // TODO removeButton
        private:
            std::vector<std::shared_ptr<RadioButton>> buttons_;
    };

}
