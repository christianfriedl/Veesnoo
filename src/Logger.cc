/*
 * Copyright (C) 2017-2018 Christian Friedl <Mag.Christian.Friedl@gmail.com>
 *
 * This file is part of Veesnoo.
 *
 * Mapitor is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */


#include<stdarg.h>
#include "Logger.h"

namespace veesnoo {

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

/*
template<typename... Args>
void log(Args&&... args) { Logger::get().log(std::forward<Args>(args)...); }
*/
void log(const std::string& msg) { Logger::get().log(msg); }

}

