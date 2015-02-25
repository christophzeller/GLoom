/*
 * GeometricObject.cpp
 *
 *  Created on: 25.02.2015
 *      Author: Christoph
 */

#include "GeometricObject.h"

GLuint GeometricObject::vertexBuffer = 0;
GLuint GeometricObject::normalBuffer = 0;
GLuint GeometricObject::tangentBuffer = 0;
GLuint GeometricObject::uvBuffer = 0;


//const glm::mat4& GeometricObject::getModelMatrix() const
//{
//	return modelMatrix;
//}

GeometricObject::GeometricObject()
	: modelMatrix(1), worldSpacePosition(0), color(1)
{
	// TODO Auto-generated constructor stub

}

GeometricObject::~GeometricObject()
{
	// TODO Auto-generated destructor stub
}

