/*
 * ActionResult.h
 *
 *  Created on: Mar 9, 2014
 *      Author: foreglance.com
 */

#ifndef ACTIONRESULT_H_
#define ACTIONRESULT_H_
#include <vector>
#include <string>

class ActionResult {
	std::vector<std::string> *m_errorMessages;
public:
	ActionResult();
	virtual ~ActionResult();
	void addError(const std::string&);
	bool isSuccess();
	std::vector<std::string>* getErrors();
};

#endif /* ACTIONRESULT_H_ */
