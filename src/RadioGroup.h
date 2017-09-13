#include <vector>
#include "ChangeEvent.h"
#include "RadioButton.h"

namespace nv {

    class RadioGroup {
        public:
            void addButton(std::shared_ptr<RadioButton> button);
            void buttonChanged(const std::shared_ptr<ChangeEvent>& ev);
                // TODO removeButton
        private:
            std::vector<std::shared_ptr<RadioButton>> buttons_;
    };

}
