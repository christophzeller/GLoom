/*
 * GLGeometricObject.h
 *
 *  Created on: 01.03.2015
 *      Author: Christoph
 */

#ifndef GLGEOMETRICOBJECT_H_
#define GLGEOMETRICOBJECT_H_

#include <glew.h>
#include "GeometricObject.h"

template<class T>
class GLGeometricObject : public GeometricObject
{
public:
protected:
	static GLuint vertexBuffer;
	static GLuint normalBuffer;
	static GLuint tangentBuffer;
	static GLuint uvBuffer;
};

template <class T>
GLuint GLGeometricObject<T>::vertexBuffer = 0;

template <class T>
GLuint GLGeometricObject<T>::normalBuffer = 0;

template <class T>
GLuint GLGeometricObject<T>::tangentBuffer = 0;

template <class T>
GLuint GLGeometricObject<T>::uvBuffer = 0;

#endif /* GLGEOMETRICOBJECT_H_ */
