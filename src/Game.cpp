
//Include Zippy
#include "Core.h"

class Game : public App
{
	glm::vec4 clearColor = glm::vec4(0.0f, 0.2f, 0.2f, 1.0f);
	Line myLine0 = Line(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	Line myLine1 = Line(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	void OnStart()
	{
	}

	void OnUpdate()
	{
		Input::PollEvents();
		if(Input::GetKeyPress(GLFW_KEY_Q)) { Quit(); };
	}

	void OnRender()
	{
		Renderer::ClearColor(clearColor);
		
		float sinval = sin(glfwGetTime()) / 2.0f + 0.5f;
		float cosval = cos(glfwGetTime()) / 2.0f + 0.5f;
		myLine0.SetPoints(-glm::vec2(sinval, cosval)*100.0f, glm::vec2(sinval, cosval)*100.0f);
		myLine0.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		myLine1.SetPoints(glm::vec2(-cosval, sinval), glm::vec2(cosval, -sinval));
		myLine1.SetColor(glm::vec4(sinval, cosval, (sinval + cosval) / 2, 1.0f));
		Renderer::DrawLine(&myLine0);
		Renderer::DrawLine(&myLine1);
//
		Renderer::SwapBuffers();
	}

	void OnEnd()
	{
	}
};

App* GetApp(void)
{
	return new Game();
}