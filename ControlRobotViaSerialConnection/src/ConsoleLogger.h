/*
 * ConsoleLogger.h
 *
 *  Created on: Mar 9, 2014
 *      Author: foreglance.com
 */

#ifndef CONSOLELOGGER_H_
#define CONSOLELOGGER_H_
#include <string>
#include <vector>
#include "ILogger.h"

class ConsoleLogger: public ILogger {
	void writeVector(const char*, std::vector<std::string>*);
public:
	virtual void writeError(const char*, ...);
	virtual void writeInfo(const char*, ...);
	virtual void writeError(std::vector<std::string>*);
	virtual void writeInfo(std::vector<std::string>*);
};

#endif /* CONSOLELOGGER_H_ */
