/*
 * Texture.h
 *
 *  Created on: 27.02.2015
 *      Author: Christoph
 */

#ifndef UTILITY_TEXTURE_H_
#define UTILITY_TEXTURE_H_

#include "GLResource.h"
#include <glew.h>

class Texture : public GLResource
{
public:
	virtual void allocate();
	virtual void free();
	void loadTexture();
	inline GLuint getTexture() { return texture; };
	Texture();
	virtual ~Texture();

private:
	GLuint texture;
};

#endif /* UTILITY_TEXTURE_H_ */
