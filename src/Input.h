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
	Input();
	static Input instance;

	/* ----- Regular class stuff ----- */
public:
	~Input();

	static bool GetKeyPress(unsigned int keyCode);

private:
	bool HiddenGetKeyPress(unsigned int keyCode);
};

#endif