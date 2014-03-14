/*
 * MainController.h
 *
 *  Created on: Mar 12, 2014
 *      Author: foreglance.com
 */

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_
#include "SerialConnection.h"
#include "ILogger.h"

class MainController {
	ILogger* m_logger;
	SerialConnection* m_conn;
public:
	MainController();
	virtual ~MainController();
	void run();
};

#endif /* MAINCONTROLLER_H_ */
