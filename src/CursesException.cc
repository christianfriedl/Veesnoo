#include "CursesException.h"

namespace nv {

const char *CursesException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _what; 
}

}
