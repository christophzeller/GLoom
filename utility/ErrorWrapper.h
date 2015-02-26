/*
 * ErrorWrapper.h
 *
 *  Created on: 24.02.2015
 *      Author: zeri
 */

#ifndef ERRORWRAPPER_H_
#define ERRORWRAPPER_H_

#include <GL/glew.h>

class ErrorWrapper
{
public:
	void printError(const char* file, const int line);
	void printError();
	ErrorWrapper();
	virtual ~ErrorWrapper();
};

#endif /* ERRORWRAPPER_H_ */
