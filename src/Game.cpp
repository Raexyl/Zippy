//LearnOpenGL Tutorial follow-along (see readme)

//In-project files
#include "Core.h"



class Game : public App
{
public: //Must be public - seg faults otherwise
	Renderer renderer = Renderer(800, 600, "Zippyyyyyyy");
	glm::vec4 clearColor = glm::vec4(0.0f, 0.2f, 0.2f, 1.0f);
	Line myLine0 = Line(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	Line myLine1 = Line(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

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