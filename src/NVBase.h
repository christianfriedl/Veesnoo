#ifndef NV_BASE_H
#define NV_BASE_H

#include <string>

namespace nv {

    const int Key_Esc = 27;

    class Exception {
    public:
        Exception(std::string msg) {}
    };

}

#endif
