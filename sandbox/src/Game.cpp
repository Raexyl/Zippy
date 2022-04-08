
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
		float sinval = sin(glfwGetTime()) / 2.0f + 0.5f;
		float cosval = cos(glfwGetTime()) / 2.0f + 0.5f;

		clearColor.x = sin(0.1f * glfwGetTime() * 3.0f) / 2.0f + 0.5f;
		clearColor.y = sin(0.1f * glfwGetTime() * 7.0f) / 2.0f + 0.5f;
		clearColor.z = sin(0.1f * glfwGetTime() * 11.0f) / 2.0f + 0.5f;

		Renderer::ClearColor(clearColor);

		glm::vec2 dims = Renderer::GetScreenDimensions();
		glm::vec4 color = glm::vec4(1, 1, 1, 1);
		Renderer::DrawLine(dims, dims * sinval, color);

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