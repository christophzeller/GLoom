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

#include "geometry/Cube.h"

#include <iostream>
#include <fstream>
#include <string>


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
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
	c.loadMesh();
	c.setPosition(glm::vec3(1.0, 0.0, 0.0));

	Texture tex;
	tex.allocate();
	tex.loadTexture();

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, tex.getTexture());

	glm::vec3 eye = glm::vec3(0.0, 2.0, -10.0);
	glm::vec3 center = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);

	glm::mat4 M;
	glm::mat4 V = glm::lookAt(eye, center, up);
	glm::mat4 MV;

	GLfloat fov = 30.0f;
	fov = glm::radians(fov);
	glm::mat4 P = glm::perspective(fov, (4.0f / 3.0f), 1.0f, 150.0f);

	c.scaleUniform(30.0f);

	glEnableVertexAttribArray(0); e.printError(__FILE__, __LINE__);
	glEnableVertexAttribArray(1); e.printError(__FILE__, __LINE__);
	glEnableVertexAttribArray(3); e.printError(__FILE__, __LINE__);

	glEnable(GL_MULTISAMPLE);

//	GLint l = glGetUniformLocation(p.getProgram(), "MV"); e.printError(__FILE__, __LINE__);
//	std::cout << "uniform MV location " << l << std::endl;

	double t = 0.0;

	while (!glfwWindowShouldClose(window))
	{
		double angle = glm::radians(t);


//		c.translate(glm::vec3(0.0, 0.0, glm::sin(angle)));
		c.rotate(angle, glm::vec3(0.0, 1.0, 0.0));

		M = c.getTranslationMatrix() * c.getRotationMatrix() * c.getScaleMatrix();

//		M = glm::mat4(1.0)* glm::rotate((float)angle, up);;
		MV = V * M;

		glClearBufferfv(GL_COLOR, 0, glm::value_ptr(colorV4)); e.printError(__FILE__, __LINE__);
		glClearBufferfv(GL_DEPTH, 0, glm::value_ptr(depth)); e.printError(__FILE__, __LINE__);

		glBindBuffer(GL_ARRAY_BUFFER, c.getVertexBuffer()); e.printError(__FILE__, __LINE__);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); e.printError(__FILE__, __LINE__);

		glBindBuffer(GL_ARRAY_BUFFER, c.getNormalBuffer()); e.printError(__FILE__, __LINE__);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); e.printError(__FILE__, __LINE__);

		glBindBuffer(GL_ARRAY_BUFFER, c.getUVBuffer()); e.printError(__FILE__, __LINE__);
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, 0); e.printError(__FILE__, __LINE__);

		GLint MVloc = glGetUniformLocation(p.getProgram(), "MV"); e.printError(__FILE__, __LINE__);
		glUniformMatrix4fv(MVloc, 1, GL_FALSE, glm::value_ptr(MV)); e.printError(__FILE__, __LINE__);

		GLint Vloc = glGetUniformLocation(p.getProgram(), "V"); e.printError(__FILE__, __LINE__);
		glUniformMatrix4fv(Vloc, 1, GL_FALSE, glm::value_ptr(V)); e.printError(__FILE__, __LINE__);

		GLint Ploc = glGetUniformLocation(p.getProgram(), "P"); e.printError(__FILE__, __LINE__);
		glUniformMatrix4fv(Ploc, 1, GL_FALSE, glm::value_ptr(P)); e.printError(__FILE__, __LINE__);

		glDrawArrays(GL_TRIANGLES, 0, 36); e.printError(__FILE__, __LINE__);
//		glDrawArrays(GL_TRIANGLES, 0, 3); e.printError(__FILE__, __LINE__);

		t += 1.0;
		// loop
		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	tex.free();

	glfwDestroyWindow(window);
	return 0;
}
