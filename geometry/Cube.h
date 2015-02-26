/*
 * Cube.h
 *
 *  Created on: 25.02.2015
 *      Author: Christoph
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "GeometricObject.h"

class Cube: public GeometricObject
{
public:
	virtual void loadMesh();
	virtual void freeMesh();
	Cube();
	virtual ~Cube();
};

#endif /* CUBE_H_ */
