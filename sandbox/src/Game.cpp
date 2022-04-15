
//Include Zippy
#include "Zippy.h"

class Game : public App
{
	glm::vec4 clearColor = glm::vec4(0.0f, 0.2f, 0.2f, 1.0f);

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

		std::vector<glm::vec2> points = {glm::vec2(0.0f, 0.0f), glm::vec2(100.0f, 100.0f)};
		RenderObjects::ClosedLoop closedLoop = RenderObjects::ClosedLoop(points);

		Renderer::DrawClosedLoop(&closedLoop);

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