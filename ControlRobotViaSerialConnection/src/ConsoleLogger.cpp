/*
 * ConsoleLogger.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: foreglance.com
 */

#include "ConsoleLogger.h"
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void ConsoleLogger::writeError(const char * format, ...){
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	printf("Error: ");
	puts(buffer);
	va_end(args);
}

void ConsoleLogger::writeInfo(const char * format, ...){
	char buffer[256];
	va_list args;
	va_start(args, format);
	vsprintf(buffer, format, args);
	printf("Info: ");
	puts(buffer);
	va_end(args);
}

void ConsoleLogger::writeError(std::vector<std::string>* messages){
	this->writeVector("Error", messages);
}

void ConsoleLogger::writeInfo(std::vector<std::string>* messages){
	this->writeVector("Info", messages);
}

void ConsoleLogger::writeVector(const char* title, std::vector<std::string>* messages){
	for(std::vector<std::string>::iterator itr = messages->begin(); itr != messages->end(); ++itr)
		std::cout << title << ": " << *itr << std::endl;
}

