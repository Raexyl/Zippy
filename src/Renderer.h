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

class Renderer
{
	void (*Render)(void);

	//Default shaders
	Shader lineShader;

	//Window details
	GLFWwindow* window;
	unsigned int width, height;

	public:
		Renderer(unsigned int width, unsigned int height, const char* windowTitle, void (*RenderFunction)(void));
		~Renderer();

		//Render Loop methods
		void ProcessInput();
		void SwapBuffers();
		void ClearColor(glm::vec4 color);
		int WindowShouldClose();

		//Render things!
		void DrawLine(Line* line);

};

/* ----- GLFW CALLBACKS! ----- */

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif