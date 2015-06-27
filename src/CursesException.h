#ifndef NV_CURSES_EXCEPTION_H
#define NV_CURSES_EXCEPTION_H

#include <exception>

namespace nv {

class CursesException: public std::exception {
public:
    CursesException(): _what("") {}
    CursesException(const char *msg): _what(msg) {}
    inline const char *what();
private:
    const char *_what;
};

}

#endif
