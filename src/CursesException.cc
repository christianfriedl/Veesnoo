#include "CursesException.h"

namespace nv {

const char *CursesException::what() { 
    return _what; 
}

}
