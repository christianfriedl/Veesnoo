#ifndef NV_LOGGER_H
#define NV_LOGGER_H

#include<string>
#include<stdio.h>

namespace nv {

class Logger {
public:
    static Logger& get();
	void log(const char *format, ...);

private:
    FILE *file;

	Logger(const std::string& fileName);
    Logger(const Logger&);
    Logger& operator=(const Logger&);
    ~Logger();

    
};

}

#endif
