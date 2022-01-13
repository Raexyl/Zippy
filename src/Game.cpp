//LearnOpenGL Tutorial follow-along (see readme)

//In-project files
#include "Core.h"

Renderer renderer(800, 600, "Zippyyyyyyy");
glm::vec4 clearColor(0.0f, 0.2f, 0.2f, 1.0f);
Line myLine0(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
Line myLine1(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

class Game : public App
{
	void OnStart()
	{
		UseRenderer(&renderer); //Must define a renderer. Fails otherwise!
	}

	void OnUpdate()
	{
		//Process Inputs
		if(glfwGetKey(renderer.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			Quit();
		}
	}

	void OnRender()
	{
		renderer.ClearColor(clearColor);
		
		float sinval = sin(glfwGetTime()) / 2.0f + 0.5f;
		float cosval = cos(glfwGetTime()) / 2.0f + 0.5f;
		myLine0.SetPoints(-glm::vec2(sinval, cosval), glm::vec2(sinval, cosval));
		myLine0.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		myLine1.SetPoints(glm::vec2(-cosval, sinval), glm::vec2(cosval, -sinval));
		myLine1.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		renderer.DrawLine(&myLine0);
		renderer.DrawLine(&myLine1);

		renderer.SwapBuffers();
		glfwPollEvents();
	}

	void OnEnd()
	{
	}
};

App* GetApp()
{
	return new Game();
}

/*
int main(void)
{	
	//Main render loop
	while(!renderer.WindowShouldClose())
	{
		renderer.ProcessInput();

		renderer.ClearColor(clearColor);

		//Render here
		renderer.DrawLine(&myLine);

		float sinval = sin(glfwGetTime()) / 2.0f + 0.5f;
		float cosval = cos(glfwGetTime()) / 2.0f + 0.5f;
		myLine.SetPoints(-glm::vec2(sinval, cosval), glm::vec2(sinval, cosval));
		myLine.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));

		renderer.SwapBuffers();
    	glfwPollEvents(); 
	}  

	glfwTerminate(); //Exit cleanly (de-allocating memory?)
    return 0;
}
*/