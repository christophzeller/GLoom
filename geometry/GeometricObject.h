/*
 * GeometricObject.h
 *
 *  Created on: 25.02.2015
 *      Author: Christoph
 */

#ifndef GEOMETRICOBJECT_H_
#define GEOMETRICOBJECT_H_

#define GLM_FORCE_RADIANS

#include <glew.h>
#include <glm.hpp>

#include <glm/gtx/transform.hpp>
#include "../utility/ErrorWrapper.h"

class GeometricObject
{
public:

	virtual void loadMesh() = 0;

	inline void setPosition(const glm::vec3& p)
	{
		worldSpacePosition = glm::vec4(p.x, p.y, p.z, 1.0);
	};

	inline void translate(const glm::vec3& p)
	{
		glm::mat4 t = glm::translate( glm::mat4(1.0), p);
//		translationMatrix += t;
		worldSpacePosition = t * worldSpacePosition;
	};

	inline void rotate(const float& angle, const glm::vec3& axis)
	{
		rotationMatrix = glm::rotate(glm::mat4(1.0), angle, axis);
	};

	// TODO: kaputt
	inline void scaleUniform(GLfloat s)
	{
		scaleMatrix = scaleMatrix * s;
	}

	inline const glm::mat4& getTranslationMatrix()
	{
		translationMatrix = glm::translate(glm::mat4(1.0),
				glm::vec3(worldSpacePosition.x, worldSpacePosition.y, worldSpacePosition.z));

		return translationMatrix;
	};

	inline const glm::mat4& getRotationMatrix() const
		{ return rotationMatrix; };

	inline const glm::mat4& getScaleMatrix() const
		{ return scaleMatrix; };

	inline const GLuint getVertexBuffer() const
	{ return vertexBuffer; };

	inline const GLuint getNormalBuffer() const
		{ return normalBuffer; };

	inline const GLuint getUVBuffer() const
		{ return uvBuffer; };


//	virtual void translate(glm::vec3 v);

	GeometricObject();
	virtual ~GeometricObject();

protected:
	static GLuint vertexBuffer;
	static GLuint normalBuffer;
	static GLuint tangentBuffer;
	static GLuint uvBuffer;

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	glm::mat4 modelMatrix;
	glm::vec4 worldSpacePosition;
	glm::vec4 color;

	ErrorWrapper err;
};

#endif /* GEOMETRICOBJECT_H_ */
