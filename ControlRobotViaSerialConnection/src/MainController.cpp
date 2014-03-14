/*
 * MainController.cpp
 *
 *  Created on: Mar 12, 2014
 *      Author: foreglance.com
 */

#include "MainController.h"
#include "ActionResult.h"
#include "ConsoleLogger.h"

MainController::MainController() {
	m_logger = new ConsoleLogger;
	m_conn = new SerialConnection(m_logger);
}

MainController::~MainController() {
	if(m_conn->isOpened())
		m_conn->closeConnection();
	delete(m_conn);
	delete(m_logger);
}

void MainController::run(){
	m_logger->writeInfo("Control robot via serial connection.");

	ActionResult actionResult = m_conn->openConnection("/dev/ttyUSB0");

	if(!actionResult.isSuccess() || !m_conn->isOpened()){
		m_logger->writeError(actionResult.getErrors());
		return;
	}

	int writtenBytes = m_conn->writeMessage("19 723test\n");
	m_logger->writeInfo("Written: %d\n", writtenBytes);
}
