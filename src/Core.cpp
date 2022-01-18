#include "Core.h"
#include "Inits.h"

int main(void)
{
	Logger::SetLogLevel(Logger::logLevel::note);
	Logger::Log("Core Starting.", Logger::logLevel::note);

	//Init GLFW, GLAD
	InitGLFW();
	if(!InitGLAD()) { return 1; };

	//We need an app
    App* a = GetApp(); 
    if(a == nullptr) { Logger::Log("No application detected. Please define function \"App* GetApp()\".", Logger::logLevel::error); return 1; };

	Logger::Log("Starting...", Logger::logLevel::note);
	a->OnStart();

	if(!a->HasRenderer()) {Logger::Log("No renderer detected. Please use \"InitWindow()\" in OnStart().", Logger::logLevel::error); return 1; }; //Must have a renderer by this point

	Logger::Log("Beginning main loop...", Logger::logLevel::note);
    while(!a->IsQuitting())
    {
        a->OnUpdate();
		a->OnRender();
    }

	Logger::Log("Quitting...", Logger::note);
    a->OnEnd();
	
    delete a;
    return 0;
}
