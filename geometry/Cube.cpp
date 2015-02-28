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
		glGenBuffers(1, &vertexBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); err.printError(__FILE__, __LINE__);

		GLfloat vertices[36 * 4] =
			{	// x, y, z, w

				// back
				-0.5, -0.5, -0.5, 1.0,
				0.5, -0.5, -0.5, 1.0,
				0.5, 0.5, -0.5, 1.0,

				0.5, 0.5, -0.5, 1.0,
				-0.5, 0.5, -0.5, 1.0,
				-0.5, -0.5, -0.5, 1.0,

				// front
				-0.5, -0.5, 0.5, 1.0,
				0.5, -0.5, 0.5, 1.0,
				0.5, 0.5, 0.5, 1.0,

				0.5, 0.5, 0.5, 1.0,
				-0.5, 0.5, 0.5, 1.0,
				-0.5, -0.5, 0.5, 1.0,

				// left
				-0.5, -0.5, -0.5, 1.0,
				-0.5, 0.5, -0.5, 1.0,
				-0.5, 0.5, 0.5, 1.0,

				-0.5, 0.5, 0.5, 1.0,
				-0.5, -0.5, 0.5, 1.0,
				-0.5, -0.5, -0.5, 1.0,

				// right
				0.5, -0.5, -0.5, 1.0,
				0.5, 0.5, -0.5, 1.0,
				0.5, 0.5, 0.5, 1.0,

				0.5, 0.5, 0.5, 1.0,
				0.5, -0.5, 0.5, 1.0,
				0.5, -0.5, -0.5, 1.0,

				// bottom
				-0.5, -0.5, -0.5, 1.0,
				0.5, -0.5, -0.5, 1.0,
				0.5, -0.5, 0.5, 1.0,

				0.5, -0.5, 0.5, 1.0,
				-0.5, -0.5, 0.5, 1.0,
				-0.5, -0.5, -0.5, 1.0,

				// top
				-0.5, 0.5, -0.5, 1.0,
				0.5, 0.5, -0.5, 1.0,
				0.5, 0.5, 0.5, 1.0,

				0.5, 0.5, 0.5, 1.0,
				-0.5, 0.5, 0.5, 1.0,
				-0.5, 0.5, -0.5, 1.0
			};

		glBufferData(GL_ARRAY_BUFFER,  sizeof(vertices),  vertices,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}



	if (normalBuffer == 0)
	{
		glGenBuffers(1, &normalBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer); err.printError(__FILE__, __LINE__);

		GLfloat normals[36 * 3] =
			{	//xyzw

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

		glBufferData(GL_ARRAY_BUFFER,  sizeof(normals),  normals,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}

	if (uvBuffer == 0)
	{
		glGenBuffers(1, &uvBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, uvBuffer); err.printError(__FILE__, __LINE__);

		GLfloat uvs[36 * 2] =
			{		//xyzw
					// back
				0.0, 0.0,
				1.0, 0.0,
				1.0, 1.0,

				1.0, 1.0,
				0.0, 1.0,
				0.0, 0.0,

				// front
				0.0, 0.0,
				4.0, 0.0,
				4.0, 4.0,

				4.0, 4.0,
				0.0, 4.0,
				0.0, 0.0,

				// left
				0.0, 0.0,
				2.0, 0.0,
				2.0, 2.0,

				2.0, 2.0,
				0.0, 2.0,
				0.0, 0.0,

				// right
				0.0, 0.0,
				8.0, 0.0,
				8.0, 8.0,

				8.0, 8.0,
				0.0, 8.0,
				0.0, 0.0,

				// bottom
				0.0, 0.0,
				4.0, 0.0,
				4.0, 4.0,

				4.0, 4.0,
				0.0, 4.0,
				0.0, 0.0,

				// top
				0.0, 0.0,
				16.0, 0.0,
				16.0, 16.0,

				16.0, 16.0,
				0.0, 16.0,
				0.0, 0.0
			};

		glBufferData(GL_ARRAY_BUFFER,  sizeof(uvs),  uvs,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}
}

void Cube::freeMesh()
{
	glDeleteBuffers(1, &vertexBuffer); err.printError(__FILE__, __LINE__);
	glDeleteBuffers(1, &normalBuffer); err.printError(__FILE__, __LINE__);
	glDeleteBuffers(1, &uvBuffer); err.printError(__FILE__, __LINE__);
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

