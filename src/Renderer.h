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
	RenderObject* objects[100]; // Array of RenderObjects
	unsigned int noObjects = 0;

	//Default shaders
	Shader lineShader;

	GLFWwindow* window;
	unsigned int width, height;

	public:
		Renderer(unsigned int width, unsigned int height, const char* windowTitle);
		~Renderer();

		void Loop(void); //Enter rendering loop;
	
	private:
		void AddRenderObject(RenderObject* renderObject);
		void ProcessInput();
};

/* ----- GLFW CALLBACKS! ----- */

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

#endif