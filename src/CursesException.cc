#include "CursesException.h"

namespace nv {

inline const char *CursesException::what() const _GLIBCXX_USE_NOEXCEPT {
    return _what; 
}

}
