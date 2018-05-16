#include "ColorSet.h"

namespace veesnoo {
    ColorSet::ColorSet(
                const ColorAttribute& contentColorAttribute, 
                const ColorAttribute& borderColorAttribute, 
                const ColorAttribute& contentFocusedColorAttribute,
                const ColorAttribute& borderFocusedColorAttribute,
                const ColorAttribute& contentEditColorAttribute,
                const ColorAttribute& borderEditColorAttribute
            ): contentColorAttribute(contentColorAttribute),
                borderColorAttribute(borderColorAttribute),
                contentFocusedColorAttribute(contentFocusedColorAttribute),
                borderFocusedColorAttribute(borderFocusedColorAttribute),
                contentEditColorAttribute(contentEditColorAttribute),
                borderEditColorAttribute(borderEditColorAttribute) 
            {}

    ColorSet ColorSet::defaultColorSets[] = { 
        /* WIDGET */ ColorSet(ColorAttribute(COLOR_WHITE, COLOR_BLACK), 
                ColorAttribute(COLOR_WHITE, COLOR_BLACK), 
                ColorAttribute(COLOR_WHITE, COLOR_BLACK), 
                ColorAttribute(COLOR_WHITE, COLOR_BLACK),
                ColorAttribute(COLOR_WHITE, COLOR_BLACK),
                ColorAttribute(COLOR_WHITE, COLOR_BLACK)
            ),
        /* TEXTBOX */ ColorSet(ColorAttribute(COLOR_WHITE, COLOR_BLACK), 
                ColorAttribute(COLOR_WHITE, COLOR_BLACK), 
                ColorAttribute(COLOR_YELLOW, COLOR_BLUE), 
                ColorAttribute(COLOR_YELLOW, COLOR_BLACK),
                ColorAttribute(COLOR_BLACK, COLOR_YELLOW), 
                ColorAttribute(COLOR_BLACK, COLOR_YELLOW)
            )
    };

    std::shared_ptr<ColorAttribute> ColorSet::getColorAttribute(WidgetClass clazz, ColorClass which) {
        switch ( which ) {
            case ColorClass::CONTENT_FOCUSED:
                return std::make_shared<ColorAttribute>(defaultColorSets[static_cast<int>(clazz)].contentFocusedColorAttribute);
            case ColorClass::CONTENT_EDIT:
                return std::make_shared<ColorAttribute>(defaultColorSets[static_cast<int>(clazz)].contentEditColorAttribute);
        }
    }

}
