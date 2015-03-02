/*
 * Cube.h
 *
 *  Created on: 25.02.2015
 *      Author: Christoph
 */

#ifndef CUBE_H_
#define CUBE_H_

//#include "GeometricObject.h"
#include "GLGeometricObject.h"

//class Cube: public GeometricObject
class Cube: public GLGeometricObject<Cube>
{
public:
	virtual void loadMesh();
	virtual void freeMesh();
	virtual void drawMesh();

	Cube();
	virtual ~Cube();
};

#endif /* CUBE_H_ */
