/*
 * Octahedron.cpp
 *
 *  Created on: 26.02.2015
 *      Author: zeri
 */

#include "Octahedron.h"
#include <glm/gtx/transform.hpp>

void Octahedron::drawMesh()
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); err.printError(__FILE__, __LINE__);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); err.printError(__FILE__, __LINE__);

	glBindBuffer(GL_ARRAY_BUFFER, normalBuffer); err.printError(__FILE__, __LINE__);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); err.printError(__FILE__, __LINE__);

//	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer); err.printError(__FILE__, __LINE__);
//	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, 0); err.printError(__FILE__, __LINE__);


	glDrawArrays(GL_TRIANGLES, 0, 24); err.printError(__FILE__, __LINE__);
}

void Octahedron::loadMesh()
{
	GLuint iterations = 1;
	for (int i = 0; i < iterations; i++)
	{
		// rotation um z
//		for (int j = 0; j < 2^i; j++)
		{
			// rotation um y
			//
		}
	}

	if (vertexBuffer == 0)
	{
		glGenBuffers(1, &vertexBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); err.printError(__FILE__, __LINE__);

//		// a
//		0.0, 0.5, 0.0, 1.0
//
//		// b
//		0.0, 0.0, 0.5, 1.0
//
//		// c
//		0.5, 0.0, 0.0, 1.0
//
//		// d
//		0.0, 0.0, -0.5, 1.0
//
//		// e
//		-0.5, 0.0, 0.0, 1.0
//
//		// f
//		0.0, -0.5, 0.0, 1.0

		GLfloat vertices[8 * 3 * 4] =
					{		// x, y, z, w

							// 1 abc
							0.0, 0.5, 0.0, 1.0,
							0.0, 0.0, 0.5, 1.0,
							0.5, 0.0, 0.0, 1.0,

							// 2 acd
							0.0, 0.5, 0.0, 1.0,
							0.5, 0.0, 0.0, 1.0,
							0.0, 0.0, -0.5, 1.0,

							// 3 ade
							0.0, 0.5, 0.0, 1.0,
							0.0, 0.0, -0.5, 1.0,
							-0.5, 0.0, 0.0, 1.0,

							// 4 aeb
							0.0, 0.5, 0.0, 1.0,
							-0.5, 0.0, 0.0, 1.0,
							0.0, 0.0, 0.5, 1.0,

							// f->a
							// 1 fbc
							0.0, -0.5, 0.0, 1.0,
							0.0, 0.0, 0.5, 1.0,
							0.5, 0.0, 0.0, 1.0,

							// 2 fcd
							0.0, -0.5, 0.0, 1.0,
							0.5, 0.0, 0.0, 1.0,
							0.0, 0.0, -0.5, 1.0,

							// 3 fde
							0.0, -0.5, 0.0, 1.0,
							0.0, 0.0, -0.5, 1.0,
							-0.5, 0.0, 0.0, 1.0,

							// 4 feb
							0.0, -0.5, 0.0, 1.0,
							-0.5, 0.0, 0.0, 1.0,
							0.0, 0.0, 0.5, 1.0
					};

			glBufferData(GL_ARRAY_BUFFER,  sizeof(vertices),  vertices,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}


	GLfloat l = 1.0 / glm::sqrt(3.0);


	if (normalBuffer == 0)
	{
		glGenBuffers(1, &normalBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer); err.printError(__FILE__, __LINE__);

		GLfloat normals[8 * 3 * 3] =
			{		//xyz

					// abc
					l, l, l,
					l, l, l,
					l, l, l,

					// acd
					l, l, -l,
					l, l, -l,
					l, l, -l,

					// ade
					-l, l, -l,
					-l, l, -l,
					-l, l, -l,

					// aeb
					-l, l, l,
					-l, l, l,
					-l, l, l,

					// fbc
					l, -l, l,
					l, -l, l,
					l, -l, l,

					// fcd
					l, -l, -l,
					l, -l, -l,
					l, -l, -l,

					// fde
					-l, -l, -l,
					-l, -l, -l,
					-l, -l, -l,

					// feb
					-l, -l, l,
					-l, -l, l,
					-l, -l, l

			};

			glBufferData(GL_ARRAY_BUFFER,  sizeof(normals),  normals,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}
}

void Octahedron::freeMesh()
{
	glDeleteBuffers(1, &vertexBuffer); err.printError(__FILE__, __LINE__);
	glDeleteBuffers(1, &normalBuffer); err.printError(__FILE__, __LINE__);
}

Octahedron::Octahedron()
{
	// TODO Auto-generated constructor stub

}

Octahedron::~Octahedron()
{
	// TODO Auto-generated destructor stub
}

