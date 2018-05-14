#ifndef NV_COLOR_SET_H
#define NV_COLOR_SET_H

#include "ColorAttribute.h"

namespace veesnoo {

    enum class WidgetClass { WIDGET, TEXTBOX };
    enum class ColorClass { CONTENT_FOCUSED };

    class ColorSet {
        public:
            ColorSet(
                const ColorAttribute& contentColorAttribute, 
                const ColorAttribute& borderColorAttribute, 
                const ColorAttribute& contentFocusedColorAttribute,
                const ColorAttribute& borderFocusedColorAttribute
            );

            ColorAttribute contentColorAttribute,
                           borderColorAttribute,
                           contentFocusedColorAttribute,
                           borderFocusedColorAttribute;

            static std::shared_ptr<ColorAttribute> getColorAttribute(WidgetClass clazz, ColorClass which);
            static ColorSet defaultColorSets[];
    };
}

#endif
