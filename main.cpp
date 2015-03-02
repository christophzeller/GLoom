#include <stdlib.h>
#include <GL/glew.h>

#define GLFW_DLL
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


#define GLM_FORCE_RADIANS
#include <glm.hpp>
//#include <glm/vec3.hpp>

#include <gtc/type_ptr.hpp>
#include <gtx/transform.hpp>


#include "utility/ShaderProgram.h"
#include "utility/Texture.h"

#include "geometry/GeometricObject.h"
#include "geometry/Cube.h"
#include "geometry/Octahedron.h"

#include <iostream>
#include <fstream>
#include <string>

#include <vector>


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}

static void cursorCallback(GLFWwindow* window, double xPos, double yPos)
{
//	std::cout << xPos << ":" << yPos << std::endl;

}


int main(int argc, char** argv)
{

	std::cout << "start" << std::endl;
	if (!glfwInit())
	{
		std::cout << "glfw init failed" << std::endl;
		exit(EXIT_FAILURE);
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Cube", 0, 0);

	if (!window)
	{
		std::cout << "window creation failed" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_SAMPLES, 4);


	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);

	glfwSetCursorPosCallback(window, cursorCallback);

	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
	{
		std::cout << glewGetErrorString(glewError) << std::endl;
	}

	ErrorWrapper e;

	std::ifstream vsSourceFile("shader/phong.vertex");
//	std::ifstream vsSourceFile("shader/singletri.vertex");
	std::string vs_source( (std::istreambuf_iterator<char>(vsSourceFile) ),
					   (std::istreambuf_iterator<char>()    ) );

	std::ifstream fsSourceFile("shader/phong.fragment");
//	std::ifstream fsSourceFile("shader/singletri.fragment");
	std::string fs_source( (std::istreambuf_iterator<char>(fsSourceFile) ),
						   (std::istreambuf_iterator<char>()    ) );

	ShaderProgram p;
	p.addShader(GL_VERTEX_SHADER, vs_source.c_str());
	p.addShader(GL_FRAGMENT_SHADER, fs_source.c_str());
	p.linkProgram();

	glUseProgram(p.getProgram()); e.printError(__FILE__, __LINE__);

	GLuint vao[2];
    glGenVertexArrays(2, vao); e.printError( __FILE__, __LINE__ );
    glBindVertexArray(vao[0]); e.printError(__FILE__, __LINE__);
    glBindVertexArray(vao[1]); e.printError(__FILE__, __LINE__);

    glEnable(GL_DEPTH_TEST); e.printError(__FILE__, __LINE__);
    glDepthFunc(GL_LESS); e.printError(__FILE__, __LINE__);

	glm::vec4 colorV4(0.3, 0.3, 0.35, 1.0);
	glm::vec4 depth(1.0);

	Cube c;
	c.setPosition(glm::vec3(1.0, 0.0, 0.0));
	c.scaleUniform(1.5f);

	Cube cc;
	cc.setPosition(glm::vec3(2.0, 1.0, 3.5));
	cc.scaleUniform(0.5f);

	Texture tex;
	tex.allocate();
	tex.loadTexture();

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, tex.getTexture());

	Octahedron o;
	o.setPosition(glm::vec3(-1.0, -0.5, -2.0));
	o.scaleUniform(0.75f);

	Octahedron oo;
	oo.setPosition(glm::vec3(-3.0, 1.0, 6.0));
	oo.scaleUniform(2.0f);
	oo.rotate(90.0f, glm::vec3(0.0, 0.0, 1.0));

	glm::vec3 eye = glm::vec3(0.0, 2.0, -10.0);
	glm::vec3 center = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);

	glm::mat4 M;
	glm::mat4 V = glm::lookAt(eye, center, up);
	glm::mat4 MV;

	GLfloat fov = 30.0f;
	fov = glm::radians(fov);
	glm::mat4 P = glm::perspective(fov, (4.0f / 3.0f), 1.0f, 150.0f);

	glEnableVertexAttribArray(0); e.printError(__FILE__, __LINE__);
	glEnableVertexAttribArray(1); e.printError(__FILE__, __LINE__);
	glEnableVertexAttribArray(3); e.printError(__FILE__, __LINE__);

	glEnable(GL_MULTISAMPLE);

//	GLint l = glGetUniformLocation(p.getProgram(), "MV"); e.printError(__FILE__, __LINE__);
//	std::cout << "uniform MV location " << l << std::endl;

//	double t = 0.0;


	std::vector<GeometricObject*> objects;
	objects.push_back(&c);
	objects.push_back(&cc);
	objects.push_back(&o);
	objects.push_back(&oo);

	for (unsigned int i = 0; i < objects.size(); i++)
		objects[i]->loadMesh();

//	std::cout << objects.size() << std::endl;

	GLint Ploc = glGetUniformLocation(p.getProgram(), "P"); e.printError(__FILE__, __LINE__);
	GLint Vloc = glGetUniformLocation(p.getProgram(), "V"); e.printError(__FILE__, __LINE__);
	GLint MVloc = glGetUniformLocation(p.getProgram(), "MV"); e.printError(__FILE__, __LINE__);

	while (!glfwWindowShouldClose(window))
	{
		double t = glfwGetTime() * 50.0f;
//		std::cout << t << std::endl;
		glClearBufferfv(GL_COLOR, 0, glm::value_ptr(colorV4)); e.printError(__FILE__, __LINE__);
		glClearBufferfv(GL_DEPTH, 0, glm::value_ptr(depth)); e.printError(__FILE__, __LINE__);

		glUniformMatrix4fv(Vloc, 1, GL_FALSE, glm::value_ptr(V)); e.printError(__FILE__, __LINE__);
		glUniformMatrix4fv(Ploc, 1, GL_FALSE, glm::value_ptr(P)); e.printError(__FILE__, __LINE__);

//		c.translate(glm::vec3(0.0, 0.0, glm::sin(angle)));
		double angle = glm::radians(t);
		c.rotate(angle * 2, glm::vec3(0.0, 1.0, 0.0));
		o.rotate(-angle, glm::vec3(0.0, 1.0, 0.0));
		cc.rotate(angle * 0.5, glm::vec3(0.0, 0.0, 1.0));
		oo.rotate(-angle, glm::vec3(0.0, 0.0, 1.0));

		for (unsigned int i = 0; i < objects.size(); i++)
		{
			M = objects[i]->getTranslationMatrix() *
				objects[i]->getRotationMatrix() *
				objects[i]->getScaleMatrix();
			MV = V * M;

			glUniformMatrix4fv(MVloc, 1, GL_FALSE, glm::value_ptr(MV)); e.printError(__FILE__, __LINE__);
			objects[i]->drawMesh();
		}

//		t += 1.0;
		// loop
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	tex.free();

	for (unsigned int i = 0; i < objects.size(); i++)
		objects[i]->freeMesh();

	glfwDestroyWindow(window);
	return 0;
}
