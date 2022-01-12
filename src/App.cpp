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

void App::Quit()
{
    m_WantToQuit = true;
}

bool App::IsQuitting()
{
    return m_WantToQuit;
}
