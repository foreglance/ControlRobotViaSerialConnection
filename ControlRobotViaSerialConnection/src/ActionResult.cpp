/*
 * ActionResult.cpp
 *
 *  Created on: Mar 9, 2014
 *      Author: foreglance.com
 */

#include "ActionResult.h"

ActionResult::ActionResult() {
	m_errorMessages = new std::vector<std::string>;
}

ActionResult::~ActionResult() {
	delete m_errorMessages;
}

void ActionResult::addError(const std::string& errorMessage){
	m_errorMessages->push_back(errorMessage);
}

bool ActionResult::isSuccess(){
	return m_errorMessages->size() <= 0;
}

std::vector<std::string>* ActionResult::getErrors(){
	return m_errorMessages;
}
