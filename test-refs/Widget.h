#ifndef BAR_H
#define BAR_H

#include <memory>
#include "Manager.h"

class Widget: public std::enable_shared_from_this<Widget> {
    public:
        Widget();
        ~Widget();

        const std::shared_ptr<Widget>& getSub();
        void setSub(const std::shared_ptr<Widget>& sub);

        const std::weak_ptr<Widget>& getParent() const;
        void setParent(const std::weak_ptr<Widget>& parent);

        void paint();
        void addOwnSub();

        void changeInternals();

        int i_;
        Manager manager_;

        std::shared_ptr<Widget> sub_;
        std::weak_ptr<Widget> parent_;

        friend std::ostream& operator<<(std::ostream& os, const Widget& widget);
};

#endif
