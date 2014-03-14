/*
 * ILogger.h
 *
 *  Created on: Mar 10, 2014
 *      Author: foreglance.com
 */

#ifndef ILOGGER_H_
#define ILOGGER_H_
#include <string>
#include <vector>

class ILogger {
public:
	virtual ~ILogger(){}
	virtual void writeError(const char*, ...) = 0;
	virtual void writeInfo(const char*, ...) = 0;
	virtual void writeError(std::vector<std::string>*) = 0;
	virtual void writeInfo(std::vector<std::string>*) = 0;
};

#endif /* ILOGGER_H_ */
