//LearnOpenGL Tutorial follow-along (see readme)

//In-project files
#include "Renderer.h"

int main(void)
{
	Renderer renderer(800, 600, "LearnOpenGL");
	
	//Main render loop
	renderer.Loop();

	glfwTerminate(); //Exit cleanly (de-allocating memory?)
    return 0;
}