/*
 * Connection.cpp
 *
 *  Created on: Mar 7, 2014
 *      Author: foreglance.com
 */

#include <iostream>
#include <exception>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include "SerialConnection.h"
using namespace std;

SerialConnection::SerialConnection(ILogger* logger) {
	m_fd = 0;
	m_logger = logger;
}

SerialConnection::~SerialConnection() {
}

ActionResult SerialConnection::openConnection(const char * deviceName) {
	ActionResult actionResult;
	try {
		m_fd = open(deviceName, O_RDWR | O_NOCTTY | O_NDELAY);
		if (m_fd == FAILED) {
			actionResult.addError("open_port: Unable to open /dev/ttyUSB0 – ");
		} else {
			fcntl(m_fd, F_SETFL, 0);
			m_logger->writeInfo("Port 1 has been successfully opened and %d is the file description\n", m_fd);
		}
		configurePort(&actionResult);
	} catch (...) {
		actionResult.addError("Unspecified error occurred");
	}
	return actionResult;
}

void SerialConnection::closeConnection(){
	if(this->isOpened())
		close(m_fd);
}

bool SerialConnection::isOpened(){
	return m_fd != FAILED && m_fd != 0;
}

int SerialConnection::writeMessage(const char* message){
	unsigned int messageLength = (unsigned) (strlen(message));
	ssize_t writtenBytes = write(m_fd, message, messageLength);
	return (int) writtenBytes;
}

void SerialConnection::configurePort(ActionResult* actionResult)
{
	struct termios serialSettings;

	if(!isatty(m_fd)) {
		actionResult->addError("Device is not \"tty\"");
		return;
	}
	if(tcgetattr(m_fd, &serialSettings) < 0) {
		actionResult->addError("Cannot get device settings");
		return;
	}

	cfsetispeed(&serialSettings, B9600);
	cfsetospeed(&serialSettings, B9600);

	serialSettings.c_cflag &= ~PARENB; // no parity
	serialSettings.c_cflag &= ~CSTOPB; //1 stop bit
	serialSettings.c_cflag &= ~CSIZE; //data size...
	serialSettings.c_cflag |= CS8; //...8 bits
	tcflush(m_fd, TCIFLUSH);
	tcsetattr(m_fd, TCSANOW, &serialSettings);
}
