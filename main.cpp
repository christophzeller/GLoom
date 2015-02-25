#include <stdlib.h>
#include <GL/glew.h>

#define GLFW_DLL
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


#define GLM_FORCE_RADIANS
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/transform.hpp>


#include "utility/ShaderProgram.h"

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

//	int maj = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
//	int min = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);

	glewInit();

	std::ifstream vsSourceFile("shader/singletri.vertex");
	std::string vs_source( (std::istreambuf_iterator<char>(vsSourceFile) ),
					   (std::istreambuf_iterator<char>()    ) );

	std::ifstream fsSourceFile("shader/singletri.fragment");
	std::string fs_source( (std::istreambuf_iterator<char>(fsSourceFile) ),
						   (std::istreambuf_iterator<char>()    ) );

	ErrorWrapper e;
	ShaderProgram s;
	s.addShader(GL_VERTEX_SHADER, vs_source.c_str());
	s.addShader(GL_FRAGMENT_SHADER, fs_source.c_str());
	s.linkProgram();


	GLuint vao;
    glGenVertexArrays(1, &vao); e.printError();
    glBindVertexArray(vao); e.printError();

	glm::vec4 colorV4(0.3, 0.3, 0.35, 1.0);

	while (!glfwWindowShouldClose(window))
	{
		glClearBufferfv(GL_COLOR, 0, glm::value_ptr(colorV4)); e.printError();

		glUseProgram(s.getProgram()); e.printError();
		glDrawArrays(GL_TRIANGLES, 0, 3); e.printError();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	std::cout << "done" << std::endl;
	return 0;
}
