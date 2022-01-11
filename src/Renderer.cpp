#include "Renderer.h"

Renderer::Renderer(unsigned int width, unsigned int height, const char* windowTitle)
{
	std::cout << "Initialising GLFW..." << std::endl;

    //InitGLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window
	window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
	if (window == NULL)
	{
    	std::cout << "Failed to create GLFW window" << std::endl;
    	glfwTerminate();
    	return;
	}
	glfwMakeContextCurrent(window);

	std::cout << "Initialising OpenGL..." << std::endl;

	//InitGLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	std::cout << "Failed to initialize GLAD" << std::endl;
    	return;
	}

	//Window Configs
	glViewport(0, 0, width, height);	//Establish co-ordinate system of window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //Allow re-sizing

	//Compiling shaders...
	std::cout << "Compiling Shaders..." << std::endl;
	lineShader = Shader("../shaders/lineShader.vs", "../shaders/lineShader.fs");
}

Renderer::~Renderer()
{
}

void Renderer::Loop(void)
{
	while(!glfwWindowShouldClose(window))
	{
		ProcessInput();

		//Clear colour
		glClearColor(0.2f, 0.4f, 0.6f, 0.5f); //State-setting
		glClear(GL_COLOR_BUFFER_BIT); //State-using

		//Render all objects
		for(unsigned int i = 0; i < noObjects; i++)
		{
			objects[i]->Draw();
		}

		//Swap Buffers, Check events
    	glfwSwapBuffers(window);
    	glfwPollEvents();  
	}  
}

void Renderer::AddRenderObject(RenderObject* renderObject)
{
	if(noObjects >= 100) {return;};
	objects[noObjects++] = renderObject;
}

//Process Inputs
void Renderer::ProcessInput()
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

/* ----- GLFW CALLBACKS! ----- */

//Callback to allow re-sizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}