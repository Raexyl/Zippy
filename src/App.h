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
        void             Quit();
        bool             IsQuitting();

    private:
        bool m_WantToQuit = false;
};

#endif