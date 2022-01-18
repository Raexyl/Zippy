#include "Inits.h"

void InitGLFW(void)
{
	//InitGLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
}

bool InitGLAD(void)
{
	
	if (glfwCreateWindow(0, 0, "Loading...", NULL, NULL) == NULL)
	{
    	Logger::Log("Failed to initialise GLFW window.", Logger::logLevel::error);
    	glfwTerminate();
    	return false;
	}
	//glfwMakeContextCurrent(window);

	//InitGLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	Logger::Log("Failed to initalise OpenGL.", Logger::logLevel::error);
    	return false;
	}
	return true;
}