#ifndef NV_COLOR_THEME_H
#define NV_COLOR_THEME_H

#include <map>
#include <string>

#include "ColorAttribute.h"

namespace veesnoo {

    class ColorTheme {
        public:
            explicit ColorTheme(const std::map<std::string, std::map<std::string, ColorAttribute>>& pColors);
            static ColorTheme whiteColorTheme();
            static ColorTheme greenColorTheme();
            static ColorTheme redColorTheme();
            static ColorTheme yellowColorTheme();
            static ColorTheme blueColorTheme();
            static ColorTheme experimentalColorTheme();

            std::map<std::string, std::map<std::string, ColorAttribute>> colors;
    };
}


#endif
