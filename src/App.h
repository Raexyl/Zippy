#ifndef APP_H
#define APP_H

#include "Renderer.h"

class App
{
    public:
        App();
        virtual ~App(); //Is this ok as virtual? It stops this line from getting a warning...
        virtual void     OnStart();
        virtual void     OnUpdate();
		virtual void 	 OnRender();
        virtual void     OnEnd();

		//Setup
		void InitialiseWindow(unsigned int width, unsigned int height, const char* windowTitle);
		
		//Exit
		bool IsQuitting();

	protected: //i.e. can be used by derivatives

		//Exit
        void Quit();
};

#endif