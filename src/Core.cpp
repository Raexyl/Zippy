#include "Core.h"

int main(void)
{
	//We need an app
    App* a = GetApp();
    if(a == nullptr) { Logger::Log("No application detected. Please define function \"App* GetApp()\".", Logger::error); return 1; };

	Logger::Log("Starting...", Logger::note);
	a->OnStart();

	if(!a->HasRenderer()) {Logger::Log("No renderer detected. Please tell Zippy to use a renderer via \"UseRenderer(Renderer*)\".", Logger::error); return 1; }; //Must have a renderer by this point

	Logger::Log("Beginning main loop...", Logger::note);
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
