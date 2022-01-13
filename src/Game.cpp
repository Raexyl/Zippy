//LearnOpenGL Tutorial follow-along (see readme)

//In-project files
#include "Core.h"

Renderer renderer(800, 600, "Zippy");
glm::vec4 clearColor(0.5f, 0.5f, 0.5f, 1.0f);
Line myLine(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

class Game : public App
{
	void OnStart()
	{
		UseRenderer(&renderer); //Must define a renderer
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
		myLine.SetPoints(-glm::vec2(sinval, cosval), glm::vec2(sinval, cosval));
		myLine.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		renderer.DrawLine(&myLine);

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