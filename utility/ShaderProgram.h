/*
 * ShaderProgram.h
 *
 *  Created on: 24.02.2015
 *      Author: zeri
 */

#ifndef SHADERPROGRAM_H_
#define SHADERPROGRAM_H_

#include <GL/glew.h>
#include "ErrorWrapper.h"

class ShaderProgram
{
public:
	inline GLuint getProgram() { return program; }
	void linkProgram();
	void addShader(GLenum type, const char* source);
	void printProgramInfoLog();
	void printShaderInfoLog(GLuint shader);
	ShaderProgram();
	virtual ~ShaderProgram();

private:
	GLuint program;
	ErrorWrapper errorWrapper;
};

#endif /* SHADERPROGRAM_H_ */
