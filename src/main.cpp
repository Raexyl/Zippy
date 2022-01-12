//LearnOpenGL Tutorial follow-along (see readme)

//In-project files
#include "Renderer.h"

//Render function
void OnRender(void)
{

}

int main(void)
{
	Renderer renderer(800, 600, "LearnOpenGL", &OnRender);
	glm::vec4 clearColor(0.5f, 0.5f, 0.5f, 1.0f);

	Line myLine(glm::vec2(0.0f, 0.0f), glm::vec2(0.3f, 0.9f), glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	
	//Main render loop
	while(!renderer.WindowShouldClose())
	{
		renderer.ProcessInput();

		renderer.ClearColor(clearColor);

		//Render here
		renderer.DrawLine(&myLine);


		renderer.SwapBuffers();
    	glfwPollEvents(); 
	}  

	glfwTerminate(); //Exit cleanly (de-allocating memory?)
    return 0;
}