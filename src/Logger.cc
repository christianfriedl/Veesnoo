#include<stdarg.h>
#include "Logger.h"

namespace nv {

Logger& Logger::get() {
    static Logger instance = Logger("test.log");
    return instance;
}

Logger::Logger(const std::string& fileName) {
    file = fopen(fileName.c_str(), "w");
}

Logger::~Logger() {
	fclose(file);
}

void Logger::log(const std::string& msg) {
    fprintf(file, "%s", msg.c_str());
	fprintf(file, "\n");
	fflush(file);
}
void Logger::log(std::unique_ptr<const std::string> msg) {
    log(*(msg.get()));
}
void Logger::log(const char *format, ...) {
	va_list argptr;
	va_start(argptr, format);
	vfprintf(file, format, argptr);
	fprintf(file, "\n");
	fflush(file);
	va_end(argptr);
}


}

