#include "App.h"


App::App()
{
}

App::~App()
{
}

void App::OnStart()
{
    //Logger::Log("Warning - The App::OnStart() method has not been overridden by a derivative of this class.");
}

void App::OnUpdate()
{
	//Logger::Log("Warning - The App::OnUpdate() method has not been overridden by a derivative of this class.");
}

void App::OnRender()
{
	//Logger::Log("Warning - The App::OnRender() method has not been overridden by a derivative of this class.");
}

void App::OnEnd()
{
	//Logger::Log("Warning - The App::OnEnd() method has not been overridden by a derivative of this class.");
}

void App::UseRenderer(Renderer* renderer)
{
	m_Renderer = renderer;
}

bool App::HasRenderer()
{
	if(m_Renderer == nullptr) {return false;};
	return true;
}

void App::Quit()
{
    glfwSetWindowShouldClose(m_Renderer->window, true);
}

bool App::IsQuitting()
{
    return glfwWindowShouldClose(m_Renderer->window);
}
