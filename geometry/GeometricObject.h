/*
 * GeometricObject.h
 *
 *  Created on: 25.02.2015
 *      Author: Christoph
 */

#ifndef GEOMETRICOBJECT_H_
#define GEOMETRICOBJECT_H_

#include <glew.h>
#include <glm.hpp>

#include "../utility/ErrorWrapper.h"

class GeometricObject
{
public:

	virtual void loadMesh() = 0;

	inline void setPosition(const glm::vec3& p)
	{ worldSpacePosition.x = p.x; worldSpacePosition.y = p.y; worldSpacePosition.z = p.z; worldSpacePosition.w = 0.0; };

	inline const glm::mat4& getModelMatrix() const
	{ return modelMatrix; };

	inline const GLuint getVertexBuffer() const
	{ return vertexBuffer; };

	inline const GLuint getNormalBuffer() const
		{ return normalBuffer; };

	inline const GLuint getUVBuffer() const
		{ return uvBuffer; };
//	virtual void scaleUniform(GLfloat s);
//	virtual void rotate(angle, axis);
//	virtual void translate(glm::vec3 v);

	GeometricObject();
	virtual ~GeometricObject();

protected:
	static GLuint vertexBuffer;
	static GLuint normalBuffer;
	static GLuint tangentBuffer;
	static GLuint uvBuffer;

	glm::mat4 modelMatrix;
	glm::vec4 worldSpacePosition;
	glm::vec4 color;

	ErrorWrapper err;
};

#endif /* GEOMETRICOBJECT_H_ */
