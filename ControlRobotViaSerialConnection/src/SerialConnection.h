/*
 * SerialConnection.h
 *
 *  Created on: Mar 7, 2014
 *      Author: foreglance.com
 */

#ifndef CONNECTION_H_
#define CONNECTION_H_
#include "ActionResult.h"
#include "ILogger.h"
#include <termios.h>

class SerialConnection {
	int m_fd;
	ILogger* m_logger;
	void configurePort(ActionResult* actionResult);
	void setSettingsFlags(struct termios* serialSettings);
	bool setCommunicationSpeed(struct termios* serialSettings,  ActionResult* actionResult);
	bool applySettings(struct termios* serialSettings,  ActionResult* actionResult);
public:
	static const int FAILED = -1;
	SerialConnection(ILogger*);
	virtual ~SerialConnection();
	ActionResult openConnection(const char*);
	void closeConnection();
	bool isOpened();
	int writeMessage(const char*);
};

#endif /* CONNECTION_H_ */
