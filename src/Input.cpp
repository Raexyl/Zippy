#include "Input.h"

#include "Renderer.h"

Input::Input(int x)
{

}

Input::~Input()
{
}

/* ----- Public *unhidden* method wrappers! ----- */

bool Input::GetKeyPress(unsigned int keyCode) { return Get().HiddenGetKeyPress(keyCode); };

void Input::PollEvents(void) { Get().HiddenPollEvents(); };

/* ----- Private *hidden* methods ----- */

bool Input::HiddenGetKeyPress(unsigned int keyCode)
{
	if(glfwGetKey(Renderer::GetWindow(), keyCode) == GLFW_PRESS) { return true; };
	return false;
}

void Input::HiddenPollEvents(void)
{
	glfwPollEvents();
}