/*
 * Octahedron.h
 *
 *  Created on: 26.02.2015
 *      Author: zeri
 */

#ifndef OCTAHEDRON_H_
#define OCTAHEDRON_H_

//#include "GeometricObject.h"
#include "GLGeometricObject.h"

//class Octahedron: public GeometricObject
class Octahedron: public GLGeometricObject<Octahedron>
{
public:
	virtual void loadMesh();
	virtual void freeMesh();
	virtual void drawMesh();
	Octahedron();
	virtual ~Octahedron();
};

#endif /* OCTAHEDRON_H_ */
