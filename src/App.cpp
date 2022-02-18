#include "App.h"

 
App::App()
{
}

App::~App()
{
}

void App::OnStart()
{
    Logger::Log("App::OnStart() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

void App::OnUpdate()
{
	Logger::Log("App::OnUpdate() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

void App::OnRender()
{
	Logger::Log("App::OnRender() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

void App::OnEnd()
{
	Logger::Log("App::OnEnd() has not been overridden by a derivative of this class.", Logger::logLevel::warning);
}

bool App::HasRenderer()
{
	if(m_Renderer == nullptr) {return false;};
	return true;
}

/* ----- Setup ----- */
void App::InitialiseWindow(unsigned int width, unsigned int height, const char* windowTitle)
{
	if(m_Renderer != nullptr) {
		delete m_Renderer;
	}
	m_Renderer = new Renderer(width, height, windowTitle);
}

/* ----- Rendering ----- */
//Clear buffer with a solid color.
void App::ClearColor(glm::vec4 color)
{
	m_Renderer->ClearColor(color);
}

//Draw the input line in the window.
void App::DrawLine(Line* line)
{
	m_Renderer->DrawLine(line);
}

//Swap the presented buffer with the hidden buffer. Updates the frame.
void App::SwapBuffers()
{
	m_Renderer->SwapBuffers();
}


/* ----- Input ----- */
//Returns true if the specified button is pressed.
bool App::GetKeyPress(unsigned int key)
{
	if(glfwGetKey(m_Renderer->window, key) == GLFW_PRESS)
	{
		return true;
	}
	return false;
}


/* ----- Exit ----- */
void App::Quit()
{
    glfwSetWindowShouldClose(m_Renderer->window, true);
}

void App::CleanUp()
{
	delete m_Renderer;
}

bool App::IsQuitting()
{
    return glfwWindowShouldClose(m_Renderer->window);
}
