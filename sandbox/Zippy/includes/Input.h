#ifndef INPUT_H
#define INPUT_H

namespace Input
{
	
	bool GetKeyPress(unsigned int keyCode);
/*!< \brief Returns whether a key is pressed.
 *
 *	Returns true if the specified key is held down, and false if it is not.
 *	Specify the key with GLFW_KEY_<character>.
 *  E.g. GLFW_KEY_Q indicates the button for 'Q' on the keyboard.
 */

	void PollEvents(void);
/*!< \brief Checks for input events.
 *
 *	Simply runs glfwPollEvents(). Should be called every frame, ideally in App::OnUpdate().
 */

};

#endif