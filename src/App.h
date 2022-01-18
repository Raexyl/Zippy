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
		bool HasRenderer();
		void InitialiseWindow(unsigned int width, unsigned int height, const char* windowTitle);
		
		//Exit
		bool IsQuitting();



	protected: //i.e. can be used by derivatives

		//Rendering
		void ClearColor(glm::vec4 color);
		void DrawLine(Line* line);
		void SwapBuffers();

		//Input management
		bool GetKeyPress(unsigned int key);

		//Exit
        void Quit();
		void CleanUp();


    private:
		Renderer* m_Renderer;
};

#endif