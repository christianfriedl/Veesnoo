#ifndef NV_COLOR_ATTRIBUTE_H
#define NV_COLOR_ATTRIBUTE_H

#include "CursesWindow.h"

namespace nv {

    class ColorAttribute {
        public:
            ColorAttribute();
            ColorAttribute(short int fg, short int bg, bool inverse = false, bool bold = false, bool underline = false, bool blink = false);
            ColorAttribute(const ColorAttribute& other);
            ColorAttribute& operator=(const ColorAttribute& other);
            ColorAttribute(ColorAttribute&& other) = delete;
            ColorAttribute& operator=(ColorAttribute&& other) = delete;
            virtual ~ColorAttribute();

            short int getFg() const { return fg_; }
            short int getBg() const { return bg_; }
            bool getInverse() const { return inverse_; }
            bool getBold() const { return bold_; }
            bool getUnderline() const { return underline_; }
            bool getBlink() const { return blink_; }

            const std::string toString() const;

            int getPairNumber() const { 
                return pairNumber_; 
            }

        private:
            short int fg_, bg_;
            bool inverse_, bold_, underline_, blink_;
            int pairNumber_;

    };

}

#endif
