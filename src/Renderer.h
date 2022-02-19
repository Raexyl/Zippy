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
	/* ----- Enforce singleton status ----- */
public:
	Renderer(const Renderer&) = delete; //Delete copy constructor
	Renderer& operator=(const Renderer&) = delete;	//Delete assignment operator

	static Renderer& Get()
	{
		return instance;
	}

private:
	Renderer(unsigned int width, unsigned int height, const char* windowTitle);
	static Renderer instance;

	/* ----- Regular class stuff ----- */
private:
	Shader lineShader; //Default shaders
	unsigned int width, height;
	GLFWwindow* window;

public:
	~Renderer();

	//Get methods
	static GLFWwindow* GetWindow();

	//Render Loop methods
	static void SwapBuffers();
	static void ClearColor(glm::vec4 color);

	//Render things!
	static void DrawLine(Line* line);

private:
	//Get methods
	GLFWwindow* HiddenGetWindow();

	//Render Loop methods
	void HiddenSwapBuffers();
	void HiddenClearColor(glm::vec4 color);

	//Render things!
	void HiddenDrawLine(Line* line);
};

/* ----- GLFW CALLBACKS! ----- */

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);

#endif