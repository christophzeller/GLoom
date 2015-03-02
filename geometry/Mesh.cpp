/*
 * Mesh.cpp
 *
 *  Created on: 28.02.2015
 *      Author: Christoph
 */

#include "Mesh.h"

void Mesh::drawMesh()
{

}

void Mesh::loadMesh()
{
	if (vertexBuffer == 0)
	{
		glGenBuffers(1, &vertexBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer); err.printError(__FILE__, __LINE__);

		// TODO: read vertices from file
		GLfloat vertices[] =
			{	// xyzw
			};

		glBufferData(GL_ARRAY_BUFFER,  sizeof(vertices),  vertices,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}

	if (normalBuffer == 0)
	{
		glGenBuffers(1, &normalBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, normalBuffer); err.printError(__FILE__, __LINE__);

		// TODO: read normals from file
		GLfloat normals[] =
			{	// xyz
			};

		glBufferData(GL_ARRAY_BUFFER,  sizeof(normals),  normals,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}

	if (uvBuffer == 0)
	{
		glGenBuffers(1, &uvBuffer); err.printError(__FILE__, __LINE__);
		glBindBuffer(GL_ARRAY_BUFFER, uvBuffer); err.printError(__FILE__, __LINE__);

		// TODO: read UVs from file
		GLfloat uvs[] =
			{	//uv
			};

		glBufferData(GL_ARRAY_BUFFER,  sizeof(uvs),  uvs,  GL_STATIC_DRAW); err.printError(__FILE__, __LINE__);
	}
}

void Mesh::freeMesh()
{
	glDeleteBuffers(1, &vertexBuffer); err.printError(__FILE__, __LINE__);
	glDeleteBuffers(1, &normalBuffer); err.printError(__FILE__, __LINE__);
	glDeleteBuffers(1, &uvBuffer); err.printError(__FILE__, __LINE__);
}

Mesh::Mesh()
{
	// TODO Auto-generated constructor stub

}

Mesh::~Mesh()
{
	// TODO Auto-generated destructor stub
}

