#ifndef NV_LOGGER_H
#define NV_LOGGER_H

#include<string>
#include<memory>
#include<stdio.h>

#define LOGMETHOD(format, args...) Logger::get().log("(%s:%i) %s [@%llx] (" format ")", __FILE__, __LINE__, __PRETTY_FUNCTION__, this, args)
#define LOG(format, args...) Logger::get().log(format, args) 

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
