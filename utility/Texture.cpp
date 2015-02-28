/*
 * Texture.cpp
 *
 *  Created on: 27.02.2015
 *      Author: Christoph
 */

#include "Texture.h"

void Texture::allocate()
{
	glGenTextures(1, &texture); e.printError(__FILE__, __LINE__);
	glBindTexture(GL_TEXTURE_2D, texture); e.printError(__FILE__, __LINE__);
}

void Texture::free()
{
	glDeleteTextures(1, &texture); e.printError(__FILE__, __LINE__);
}

void Texture::loadTexture()
{
	// blue/white checkerboard
	GLfloat data[] =
		{
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,

			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,

			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,

			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f, 1.0f

		};

	glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA, 4, 4); e.printError(__FILE__, __LINE__);

	glTexSubImage2D(GL_TEXTURE_2D,
			0,
			0, 0,
			4, 4,
			GL_RGBA,
			GL_FLOAT,
			data);
	e.printError(__FILE__, __LINE__);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);e.printError(__FILE__, __LINE__);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);e.printError(__FILE__, __LINE__);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);e.printError(__FILE__, __LINE__);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);e.printError(__FILE__, __LINE__);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);e.printError(__FILE__, __LINE__);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1000);e.printError(__FILE__, __LINE__);

	glGenerateMipmap(GL_TEXTURE_2D);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA32F, GL_FLOAT, data); e.printError(__FILE__, __LINE__);
}

Texture::Texture() : texture(0)
{
	// TODO Auto-generated constructor stub

}

Texture::~Texture()
{
	// TODO Auto-generated destructor stub
}

