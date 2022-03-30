#ifndef INPUT_H
#define INPUT_H

class Input
{
	/* ----- Enforce singleton status ----- */
public:
	Input(const Input&) = delete; //Delete copy constructor
	Input& operator=(const Input&) = delete;	//Delete assignment operator

	static Input& Get()
	{
		return instance;
	}

private:
	Input(int x); //For some reason the constructor needs an argument!? Even if the argument does nothing!?
	static Input instance;

	/* ----- Regular class stuff ----- */
public:
	~Input();

	static bool GetKeyPress(unsigned int keyCode);
	/*!< \brief Returns whether a key is pressed.
 *
 *	Returns true if the specified key is held down, and false if it is not.
 *	Specify the key with GLFW_KEY_<character>.
 *  E.g. GLFW_KEY_Q indicates the button for 'Q' on the keyboard.
 */

	static void PollEvents(void);

private:
	bool HiddenGetKeyPress(unsigned int keyCode);
	void HiddenPollEvents(void);
};

#endif