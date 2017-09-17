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


#ifndef NV_LOGGER_H
#define NV_LOGGER_H

#include<string>
#include<memory>
#include<stdio.h>

#define LOGMETHODONLY() Logger::get().log("(%s:%i) %s [@%llx] ()", __FILE__, __LINE__, __PRETTY_FUNCTION__, this)
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
