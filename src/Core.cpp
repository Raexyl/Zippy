#include "Core.h"

int main(void)
{
	//We need an app
    App* a = GetApp();
    if(a == nullptr) {return 1;};

	a->OnStart();

	if(!a->HasRenderer()) {return 1;}; //Must have a renderer by this point

    while(!a->IsQuitting())
    {
        a->OnUpdate();
		a->OnRender();
    }

    a->OnEnd();
	
    delete a;
    return 0;
}
