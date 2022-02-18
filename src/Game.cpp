//LearnOpenGL Tutorial follow-along (see readme)

//In-project files
#include "Core.h"


class Game : public App
{
	glm::vec4 clearColor = glm::vec4(0.0f, 0.2f, 0.2f, 1.0f);
	//Line myLine0 = Line(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)); //Removing this will remove the segfault.
	//Line myLine1 = Line(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	void OnStart()
	{
		InitialiseWindow(800, 600, "|ZIP|");
	}

	void OnUpdate()
	{
		//Process Inputs
		if(GetKeyPress(GLFW_KEY_Q))
		{
			Quit();
		}
	}

	void OnRender()
	{
		ClearColor(clearColor);
		//
		//float sinval = sin(glfwGetTime()) / 2.0f + 0.5f;
		//float cosval = cos(glfwGetTime()) / 2.0f + 0.5f;
		//myLine0.SetPoints(-glm::vec2(sinval, cosval), glm::vec2(sinval, cosval));
		//myLine0.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		//myLine1.SetPoints(glm::vec2(-cosval, sinval), glm::vec2(cosval, -sinval));
		//myLine1.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		//DrawLine(&myLine0);
		//DrawLine(&myLine1);
//
		SwapBuffers();
		glfwPollEvents();
	}

	void OnEnd()
	{
		CleanUp();
	}
};

App* GetApp(void)
{
	return new Game();
}