/*
 * Cube.cpp
 *
 *  Created on: 25.02.2015
 *      Author: Christoph
 */

#include "Cube.h"

#include <iostream>

void Cube::loadMesh()
{
	if (vertexBuffer == 0)
	{
		glGenBuffers(1, &vertexBuffer); err.printError();
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); err.printError();
	}

	GLfloat vertices[36 * 4] =
	{		// x, y, z, w

			// back
			0.0, 0.0, 0.0, 1.0,
			1.0, 0.0, 0.0, 1.0,
			1.0, 1.0, 0.0, 1.0,

			1.0, 1.0, 0.0, 1.0,
			0.0, 1.0, 0.0, 1.0,
			0.0, 0.0, 0.0, 1.0,

			// front
			0.0, 0.0, 1.0, 1.0,
			1.0, 0.0, 1.0, 1.0,
			1.0, 1.0, 1.0, 1.0,

			1.0, 1.0, 1.0, 1.0,
			0.0, 1.0, 1.0, 1.0,
			0.0, 0.0, 1.0, 1.0,

			// left
			0.0, 0.0, 0.0, 1.0,
			0.0, 1.0, 0.0, 1.0,
			0.0, 1.0, 1.0, 1.0,

			0.0, 1.0, 1.0, 1.0,
			0.0, 0.0, 1.0, 1.0,
			0.0, 0.0, 0.0, 1.0,

			// right
			1.0, 0.0, 0.0, 1.0,
			1.0, 1.0, 0.0, 1.0,
			1.0, 1.0, 1.0, 1.0,

			1.0, 1.0, 1.0, 1.0,
			1.0, 0.0, 1.0, 1.0,
			1.0, 0.0, 0.0, 1.0,

			// bottom
			0.0, 0.0, 0.0, 1.0,
			1.0, 0.0, 0.0, 1.0,
			1.0, 0.0, 1.0, 1.0,

			1.0, 0.0, 1.0, 1.0,
			0.0, 0.0, 1.0, 1.0,
			0.0, 0.0, 0.0, 1.0,

			// top
			0.0, 1.0, 0.0, 1.0,
			1.0, 1.0, 0.0, 1.0,
			0.0, 1.0, 1.0, 1.0,

			1.0, 1.0, 1.0, 1.0,
			0.0, 1.0, 1.0, 1.0,
			0.0, 1.0, 0.0, 1.0
	};


//	static const GLfloat vertices[] = { -1.0f,-1.0f,-1.0f, 1.0f,
//	    -1.0f,-1.0f, 1.0f, 1.0f,
//	    -1.0f, 1.0f, 1.0f,  1.0f,
//	    1.0f, 1.0f,-1.0f,  1.0f,
//	    -1.0f,-1.0f,-1.0f, 1.0f,
//	    -1.0f, 1.0f,-1.0f, 1.0f,
//	    1.0f,-1.0f, 1.0f, 1.0f,
//	    -1.0f,-1.0f,-1.0f, 1.0f,
//	    1.0f,-1.0f,-1.0f, 1.0f,
//	    1.0f, 1.0f,-1.0f, 1.0f,
//	    1.0f,-1.0f,-1.0f, 1.0f,
//	    -1.0f,-1.0f,-1.0f, 1.0f,
//	    -1.0f,-1.0f,-1.0f, 1.0f,
//	    -1.0f, 1.0f, 1.0f, 1.0f,
//	    -1.0f, 1.0f,-1.0f, 1.0f,
//	    1.0f,-1.0f, 1.0f, 1.0f,
//	    -1.0f,-1.0f, 1.0f, 1.0f,
//	    -1.0f,-1.0f,-1.0f, 1.0f,
//	    -1.0f, 1.0f, 1.0f, 1.0f,
//	    -1.0f,-1.0f, 1.0f, 1.0f,
//	    1.0f,-1.0f, 1.0f, 1.0f,
//	    1.0f, 1.0f, 1.0f, 1.0f,
//	    1.0f,-1.0f,-1.0f, 1.0f,
//	    1.0f, 1.0f,-1.0f, 1.0f,
//	    1.0f,-1.0f,-1.0f, 1.0f,
//	    1.0f, 1.0f, 1.0f, 1.0f,
//	    1.0f,-1.0f, 1.0f, 1.0f,
//	    1.0f, 1.0f, 1.0f, 1.0f,
//	    1.0f, 1.0f,-1.0f, 1.0f,
//	    -1.0f, 1.0f,-1.0f, 1.0f,
//	    1.0f, 1.0f, 1.0f, 1.0f,
//	    -1.0f, 1.0f,-1.0f, 1.0f,
//	    -1.0f, 1.0f, 1.0f, 1.0f,
//	    1.0f, 1.0f, 1.0f, 1.0f,
//	    -1.0f, 1.0f, 1.0f, 1.0f,
//	    1.0f,-1.0f, 1.0f,1.0f  };

	//	GL_ARRAY_BUFFER, 36 * 4 * sizeof(vertices)
	glBufferData(GL_ARRAY_BUFFER,  sizeof(vertices),  vertices,  GL_STATIC_DRAW); err.printError();
//	glDeleteBuffers(1, &vertexBuffer); err.printError();

	if (normalBuffer == 0)
	{
		glGenBuffers(1, &normalBuffer); err.printError();
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer); err.printError();
	}

	GLfloat normals[36 * 3] =
	{		//xyzw

			// back
			0.0, 0.0, -1.0,
			0.0, 0.0, -1.0,
			0.0, 0.0, -1.0,

			0.0, 0.0, -1.0,
			0.0, 0.0, -1.0,
			0.0, 0.0, -1.0,

			// front
			0.0, 0.0, 1.0,
			0.0, 0.0, 1.0,
			0.0, 0.0, 1.0,

			0.0, 0.0, 1.0,
			0.0, 0.0, 1.0,
			0.0, 0.0, 1.0,

			// left
			-1.0, 0.0, 0.0,
			-1.0, 0.0, 0.0,
			-1.0, 0.0, 0.0,

			-1.0, 0.0, 0.0,
			-1.0, 0.0, 0.0,
			-1.0, 0.0, 0.0,

			// right
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,

			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,

			// bottom
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,

			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,

			// top
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,

			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f


	};

	glBufferData(GL_ARRAY_BUFFER,  sizeof(normals),  normals,  GL_STATIC_DRAW); err.printError();
//	glDeleteBuffers(1, &normalBuffer); err.printError();

}

Cube::Cube()
	: GeometricObject()
{
	// TODO Auto-generated constructor stub

}

Cube::~Cube()
{
	// TODO Auto-generated destructor stub
}

