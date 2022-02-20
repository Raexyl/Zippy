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
	static void PollEvents(void);

private:
	bool HiddenGetKeyPress(unsigned int keyCode);
	void HiddenPollEvents(void);
};

#endif