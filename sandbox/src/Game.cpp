
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
		float cosval = cos(glfwGetTime()) / 2.0f + 0.5f;
		glm::vec2 dims = Renderer::GetScreenDimensions();

		//Testing closedloop drawing
		glm::vec2 points[4] = {	glm::vec2(0.0f, dims.y * cosval),
								glm::vec2(dims.x, dims.y * sinval / 2.0f),
								glm::vec2(dims.x * cosval, dims.y * sinval),
								glm::vec2(dims.x/2.0f, dims.y/2.0f)
								};
		Renderer::DrawClosedLoop(points, 4, glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

		//Drawing a line
		glm::vec2 start = {0.0f, 0.0f};
		glm::vec2 end = {100.0f, 200.0f * sinval};
		glm::vec4 color = {1.0f, 1.0f, 1.0f, 1.0f};
		Renderer::DrawLine(start, end, color);

		Renderer::DrawPolygon(6, 100.0f, dims/2.0f, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

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