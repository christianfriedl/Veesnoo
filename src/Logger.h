#ifndef NV_LOGGER_H
#define NV_LOGGER_H

#include<string>
#include<memory>
#include<stdio.h>

#define LOG(classname, funcname, format, args...) Logger::get().log("%s::%s[@%llx]( " format ")", classname, funcname, this, args)

namespace nv {

class Logger {
public:
    static Logger& get();
	void log(const char *format, ...);
	void log(const std::string& msg);
    void log(std::unique_ptr<const std::string> msg);

private:
    FILE *file;

	Logger(const std::string& fileName);
    Logger(const Logger&);
    Logger& operator=(const Logger&);
    ~Logger();
};

/* TODO this does not work yet
template<typename... Args>
void log(Args&&... args);
*/
void log(const std::string& msg);

}

#endif
