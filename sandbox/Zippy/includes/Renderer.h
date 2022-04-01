#ifndef RENDERER_H
#define RENDERER_H

//Logging (& debugging)
#include <iostream>

//External includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

//Files from this project
#include "Shader.h"
#include "Line.h"

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
	Shader m_LineShader; //Default shaders
	unsigned int m_Width, m_Height;
	GLFWwindow* m_Window;
	bool successfulInitialisation = false;

public:
	~Renderer();

	//Get methods
	static GLFWwindow* GetWindow();
	static glm::vec2 GetScreenDimensions();
	static bool InitialisedSuccessfully();

	//Setup stuff
	static void SetWindowTitle(const char* string);
	static void SetWindowSize(unsigned int width, unsigned int height);

	//Render Loop methods
	static void SwapBuffers();
	static void ClearColor(glm::vec4 color);

	//Render things!
	static void DrawLine(Line* line);

	//Callbacks
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
	//Get methods
	GLFWwindow* HiddenGetWindow();
	glm::vec2 HiddenGetScreenDimensions();
	bool HiddenInitialisedSuccessfully();

	//Setup
	void HiddenSetWindowTitle(const char* string);
	void HiddenSetWindowSize(unsigned int width, unsigned int height);

	//Render Loop methods
	void HiddenSwapBuffers();
	void HiddenClearColor(glm::vec4 color);

	//Render things!
	void HiddenDrawLine(Line* line);

	//Callbacks
	void hidden_framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

/* ----- GLFW CALLBACKS! ----- */

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);

#endif