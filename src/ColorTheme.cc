#include "ColorTheme.h"

namespace veesnoo {

    ColorTheme::ColorTheme(const std::map<std::string, std::map<std::string, ColorAttribute>>& pColors): colors(pColors) {
    }

    ColorTheme ColorTheme::defaultColorTheme() {
        const std::map<std::string, std::map<std::string, ColorAttribute>> colorMap = 
        {
            { "Widget", { 
                { "content", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
            } }
        }
            ;
        return ColorTheme(colorMap);
    }
}
