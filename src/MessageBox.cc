#include "Logger.h"
#include "MessageBox.h"

namespace nv {

    MessageBox::MessageBox(const std::string& title, const std::string& text): Window(Rect(0, 0, 1, 1), title) {
        label_ = std::make_shared<Label>(text, 1, 1);
    }

    MessageBox::~MessageBox() {}

    const std::shared_ptr<MessageBox> MessageBox::create(const std::string& title, const std::string& text) {
        auto mb = std::make_shared<MessageBox>(title, text);
        mb->addWidget(mb->getLabel());
        mb->layout();
        return mb;
    }

    const std::shared_ptr<Label> MessageBox::getLabel() {
        return label_;
    }

    void MessageBox::layout() {
        int maxTextLen = std::max(title_.length(), (unsigned long)label_->getRect().getWidth()); // TODO utf8-ize
        resize(maxTextLen + 5, 8); // TODO whatevs
        int labelX = std::max(rect_.getWidth() / 2 - maxTextLen / 2 - 1, 0);
        int labelY = std::max(rect_.getHeight() / 2 - 1, 0);
        label_->move(labelX, labelY);
        Logger::get().log("MB2 contentRect_ %s", contentRect_.toString()->c_str());
        if ( parent_.use_count() != 0 ) { // we have a parent
            auto parent = parent_.lock();
            if ( parent == nullptr )
                throw std::runtime_error("Parent found, but not accessible.");
            int x = std::max(parent->getContentRect().getWidth() / 2 - rect_.getWidth() / 2, 0);
            int y = std::max(parent->getContentRect().getHeight() / 2 - rect_.getHeight() / 2, 0);
            move(x, y);
        }
    }

}
