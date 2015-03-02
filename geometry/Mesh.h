/*
 * Mesh.h
 *
 *  Created on: 28.02.2015
 *      Author: Christoph
 */

#ifndef MESH_H_
#define MESH_H_

#include "GLGeometricObject.h"

class Mesh: public GLGeometricObject<Mesh>
{
public:
	virtual void loadMesh();
	virtual void freeMesh();
	virtual void drawMesh();
	Mesh();
	virtual ~Mesh();
};

#endif /* MESH_H_ */
