
//Include Zippy
#include "Zippy.h"

class Game : public App
{
	glm::vec4 clearColor = glm::vec4(0.0f, 0.2f, 0.2f, 1.0f);
	Line myLine0 = Line(glm::vec2(0.0f, 0.0f), Renderer::GetScreenDimensions(), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	void OnStart()
	{
		Renderer::SetWindowTitle("Zippy Sandbox");
		Renderer::SetWindowSize(800, 450);
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

		glm::vec2 points[3] = {	glm::vec2(0.0f, 0.0f),
								glm::vec2(sinval * 50.0f, 50.0f),
								Renderer::GetScreenDimensions()
													};

		Renderer::DrawClosedLoop(points, 3);

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