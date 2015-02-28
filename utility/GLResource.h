/*
 * GLResource.h
 *
 *  Created on: 27.02.2015
 *      Author: Christoph
 */

#ifndef UTILITY_GLRESOURCE_H_
#define UTILITY_GLRESOURCE_H_

#include "ErrorWrapper.h"

class GLResource
{
public:
	virtual void allocate() = 0;
	virtual void free() = 0;
	GLResource();
	virtual ~GLResource();

protected:
	ErrorWrapper e;
};

#endif /* UTILITY_GLRESOURCE_H_ */
