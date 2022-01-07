//Test GLAD and GLFW3 together, no extras

//Logging (& debugging)
#include <iostream>

//Graphics
#include "glad/glad.h"
#include "GLFW/glfw3.h"

//Callback to allow re-sizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main(void)
{
    std::cout << "Starting..." << std::endl;

    //InitGLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
    	std::cout << "Failed to create GLFW window" << std::endl;
    	glfwTerminate();
    	return -1;
	}
	glfwMakeContextCurrent(window);

	//InitGLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	std::cout << "Failed to initialize GLAD" << std::endl;
    	return -1;
	}

	//More initial configs
	glViewport(0, 0, 800, 600);	//Establish co-ordinate system of window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //Allow re-sizing

	//Main render loop
	while(!glfwWindowShouldClose(window))
	{
    	glfwSwapBuffers(window);
    	glfwPollEvents();    
	}


	glfwTerminate();
    return 0;
}