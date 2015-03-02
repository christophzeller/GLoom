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
	// TODO: composition using LoadStrategy ?
	void loadTexture();
	inline GLuint getTexture() { return texture; };
	Texture();
	virtual ~Texture();

	void generate(GLfloat* data, int size);
	void readFile(GLfloat* data);
	inline void setFile(const char* path) { file = path; } ;

private:
	GLuint texture;
	const char* file;
};

#endif /* UTILITY_TEXTURE_H_ */
