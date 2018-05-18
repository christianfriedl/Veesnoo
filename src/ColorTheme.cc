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
            } },
            { "Window", { 
                { "content", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_WHITE, COLOR_BLACK) },
            } },
        }
        ;
        return ColorTheme(colorMap);
    }

    ColorTheme ColorTheme::greenColorTheme() {
        const std::map<std::string, std::map<std::string, ColorAttribute>> colorMap = 
        {
            { "Widget", { 
                { "content", ColorAttribute(COLOR_GREEN, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_GREEN, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_BLACK, COLOR_GREEN) },
                { "focusedBorder", ColorAttribute(COLOR_BLACK, COLOR_GREEN) },
            } },
            { "Window", { 
                { "content", ColorAttribute(COLOR_GREEN, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_GREEN, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_GREEN, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_GREEN, COLOR_BLACK) },
            } },
        }
        ;
        return ColorTheme(colorMap);
    }

    ColorTheme ColorTheme::redColorTheme() {
        const std::map<std::string, std::map<std::string, ColorAttribute>> colorMap = 
        {
            { "Widget", { 
                { "content", ColorAttribute(COLOR_RED, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_RED, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_BLACK, COLOR_RED) },
                { "focusedBorder", ColorAttribute(COLOR_BLACK, COLOR_RED) },
            } },
            { "Window", { 
                { "content", ColorAttribute(COLOR_RED, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_RED, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_RED, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_RED, COLOR_BLACK) },
            } },
        }
        ;
        return ColorTheme(colorMap);
    }
}
