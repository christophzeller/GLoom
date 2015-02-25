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
		std::cout << "kaputt 1" << std::endl;
		exit(EXIT_FAILURE);
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "", 0, 0);

	if (!window)
	{
		std::cout << "kaputt 2" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);

	glewInit();

	ErrorWrapper e;

	std::ifstream vsSourceFile("shader/phong.vertex");
	std::string vs_source( (std::istreambuf_iterator<char>(vsSourceFile) ),
					   (std::istreambuf_iterator<char>()    ) );

	std::ifstream fsSourceFile("shader/phong.fragment");
	std::string fs_source( (std::istreambuf_iterator<char>(fsSourceFile) ),
						   (std::istreambuf_iterator<char>()    ) );

	ShaderProgram p;
	p.addShader(GL_VERTEX_SHADER, vs_source.c_str());
	p.addShader(GL_FRAGMENT_SHADER, fs_source.c_str());
	p.linkProgram();

	glUseProgram(p.getProgram());

	GLuint vao[2];
    glGenVertexArrays(2, vao); e.printError();
    glBindVertexArray(vao[0]); e.printError();
    glBindVertexArray(vao[1]); e.printError();

    glEnable(GL_DEPTH_TEST); e.printError();
    glDepthFunc(GL_LESS); e.printError();

	glm::vec4 colorV4(0.3, 0.3, 0.35, 1.0);
	glm::vec4 depth(1.0);

	Cube c;
	c.loadMesh();

	glm::vec3 eye = glm::vec3(5.0, 2.0, 5.0);
	glm::vec3 center = glm::vec3(0.0, 0.0, 0.0);
	glm::vec3 up = glm::vec3(0.0, 1.0, 0.0);

	glm::mat4 M = glm::mat4(1.0);
	glm::mat4 V = glm::lookAt(eye, center, up);

	GLfloat fov = 30.0f;

	fov = glm::radians(fov);
	glm::mat4 P = glm::perspective(fov, (4.0f / 3.0f), 1.0f, 50.0f);

	glm::mat4 MV = V * M;

	while (!glfwWindowShouldClose(window))
	{
		glClearBufferfv(GL_COLOR, 0, glm::value_ptr(colorV4)); e.printError(); //std::cout << "1" << std::endl;
		glClearBufferfv(GL_DEPTH, 0, glm::value_ptr(depth)); e.printError();

		glBindBuffer(GL_ARRAY_BUFFER, c.getVertexBuffer()); e.printError(); //std::cout << "2" << std::endl;
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0); e.printError(); //std::cout << "3" << std::endl;
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, c.getNormalBuffer()); e.printError(); //std::cout << "4" << std::endl;
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); e.printError(); //std::cout << "5" << std::endl;
		glEnableVertexAttribArray(1);

		glUniformMatrix4fv(10, 1, GL_FALSE, glm::value_ptr(MV)); e.printError(); //std::cout << "6" << std::endl;
//		glUniformMatrix4fv(11, 1, GL_FALSE, glm::value_ptr(V)); e.printError(); std::cout << "7" << std::endl;

		glUniformMatrix4fv(12, 1, GL_FALSE, glm::value_ptr(P)); e.printError(); //std::cout << "8" << std::endl;

		glDrawArrays(GL_TRIANGLES, 0, 36); e.printError(); //std::cout << "9" << std::endl;

//		glUseProgram(s.getProgram()); e.printError();
//		glDrawArrays(GL_TRIANGLES, 0, 3); e.printError();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	return 0;
}
