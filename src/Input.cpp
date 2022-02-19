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

/* ----- Private *hidden* methods ----- */

bool Input::HiddenGetKeyPress(unsigned int keyCode)
{
	if(glfwGetKey(Renderer::GetWindow(), keyCode) == GLFW_PRESS) { return true; };
	return false;
}