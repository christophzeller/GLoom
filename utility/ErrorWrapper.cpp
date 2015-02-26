/*
 * ErrorWrapper.cpp
 *
 *  Created on: 24.02.2015
 *      Author: zeri
 */

#include "ErrorWrapper.h"
#include <iostream>

void ErrorWrapper::printError(const char* file, const int line)
{
	GLenum code = glGetError();
	if (code != 0)
		std::cout << code << " " << glewGetErrorString(code) << "@" << file << ":" << line << std::endl;

}

void ErrorWrapper::printError()
{
	GLenum code = glGetError();
	if (code != 0)
		std::cout << code << " " << glewGetErrorString(code) << std::endl;

}

ErrorWrapper::ErrorWrapper()
{
	// TODO Auto-generated constructor stub

}

ErrorWrapper::~ErrorWrapper()
{
	// TODO Auto-generated destructor stub
}

