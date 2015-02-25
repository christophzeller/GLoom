/*
 * ShaderProgram.cpp
 *
 *  Created on: 24.02.2015
 *      Author: zeri
 */

#include "ShaderProgram.h"
#include <iostream>
#include <GL/glew.h>

void ShaderProgram::linkProgram()
{
	glLinkProgram(program);
	errorWrapper.printError();

	printProgramInfoLog();
}

void ShaderProgram::addShader(GLenum type, const char* source)
{
	if (program == 0)
	{
		program = glCreateProgram();
	}

	std::cout << "compiling..." << std::endl << source << std::endl;

	GLuint shader = glCreateShader(type);
	errorWrapper.printError();

	glShaderSource(shader, 1, &source, 0);
	errorWrapper.printError();

	glCompileShader(shader);
	errorWrapper.printError();

	glAttachShader(program, shader);
	errorWrapper.printError();

	printShaderInfoLog(shader);
}

void ShaderProgram::printProgramInfoLog()
{
	GLint p;
	glGetProgramiv(program,  GL_INFO_LOG_LENGTH,  &p);
	errorWrapper.printError();

	if (!p)
		return;

	GLsizei logL = p;
	//glGetShaderInfoLog(GLuint shader,  GLsizei maxLength,  GLsizei *length,  GLchar *infoLog);

	GLchar log[1024];



	glGetProgramInfoLog(program,  1024,  &logL,  log);

	std::cout << log << std::endl;

	errorWrapper.printError();
}

void ShaderProgram::printShaderInfoLog(GLuint shader)
{
	//glGetShaderInfoLog(GLuint shader,  GLsizei maxLength,  GLsizei *length,  GLchar *infoLog);

	GLint p;
	glGetShaderiv(shader,  GL_INFO_LOG_LENGTH,  &p);
	errorWrapper.printError();

	if (!p)
		return;

	GLchar log[511];
	GLsizei maxL = 511;
	GLsizei logL;

	glGetShaderInfoLog(shader,  maxL,  &logL,  log);
	errorWrapper.printError();

	std::cout << log << std::endl;

}

ShaderProgram::ShaderProgram() : program(0)
{

}

ShaderProgram::~ShaderProgram()
{
	if (program != 0)
	{
		glDeleteProgram(program);
	}
}

