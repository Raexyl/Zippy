#include "Input.h"

#include "Renderer.h"

bool Input::GetKeyPress(unsigned int keyCode)
{
	if(glfwGetKey(Renderer::GetWindow(), keyCode) == GLFW_PRESS) { return true; };
	return false;
}

void Input::PollEvents(void)	
{
	glfwPollEvents();
}

