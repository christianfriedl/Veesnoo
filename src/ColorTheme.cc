#include "ColorTheme.h"

namespace veesnoo {

    ColorTheme::ColorTheme(const std::map<std::string, std::map<std::string, ColorAttribute>>& pColors): colors(pColors) {
    }

    ColorTheme ColorTheme::whiteColorTheme() {
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

    ColorTheme ColorTheme::yellowColorTheme() {
        const std::map<std::string, std::map<std::string, ColorAttribute>> colorMap = 
        {
            { "Widget", { 
                { "content", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_BLACK, COLOR_YELLOW) },
                { "focusedBorder", ColorAttribute(COLOR_BLACK, COLOR_YELLOW) },
            } },
            { "Window", { 
                { "content", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
            } },
        }
        ;
        return ColorTheme(colorMap);
    }

    ColorTheme ColorTheme::blueColorTheme() {
        const std::map<std::string, std::map<std::string, ColorAttribute>> colorMap = 
        {
            { "Widget", { 
                { "content", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_YELLOW, COLOR_BLUE) },
                { "focusedBorder", ColorAttribute(COLOR_YELLOW, COLOR_BLUE) },
            } },
            { "Window", { 
                { "content", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
            } },
        }
        ;
        return ColorTheme(colorMap);
    }

    ColorTheme ColorTheme::experimentalColorTheme() {
        const std::map<std::string, std::map<std::string, ColorAttribute>> colorMap = 
        {
            { "Widget", { 
                { "content", ColorAttribute(COLOR_YELLOW, COLOR_MAGENTA) },
                { "border", ColorAttribute(COLOR_YELLOW, COLOR_MAGENTA) },
                { "focusedContent", ColorAttribute(COLOR_MAGENTA, COLOR_CYAN) },
                { "focusedBorder", ColorAttribute(COLOR_MAGENTA, COLOR_BLACK) },
            } },
            { "Window", { 
                { "content", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "border", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "focusedContent", ColorAttribute(COLOR_BLUE, COLOR_BLACK) },
                { "focusedBorder", ColorAttribute(COLOR_YELLOW, COLOR_BLACK) },
            } },
        }
        ;
        return ColorTheme(colorMap);
    }
}
