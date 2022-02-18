#ifndef RENDERER_H
#define RENDERER_H

//Logging (& debugging)
#include <iostream>

//Graphics
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

//Files from this project
#include "Shader.h"
#include "Line.h"
#include "Logger.h"

//Singleton!
class Renderer
{
	//Enforce singleton status
	static Renderer* instance;
	private: Renderer(unsigned int width, unsigned int height, const char* windowTitle);

	//Default shaders
	Shader lineShader;

	//Window details
	unsigned int width, height;

	public:
	GLFWwindow* window;

	public:

		static Renderer *GetInstance();
		~Renderer();

		//Render Loop methods
		void SwapBuffers();
		void ClearColor(glm::vec4 color);

		//Render things!
		void DrawLine(Line* line);
};

/* ----- GLFW CALLBACKS! ----- */

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif