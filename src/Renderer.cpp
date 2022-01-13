#include "Renderer.h"

Renderer::Renderer(unsigned int width, unsigned int height, const char* windowTitle)
{
	Logger::Log("Initalising GLFW...", Logger::note);

    //InitGLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window
	window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
	if (window == NULL)
	{
    	Logger::Log("Failed to initialise GLFW window.", Logger::error);
    	glfwTerminate();
    	return;
	}
	glfwMakeContextCurrent(window);

	Logger::Log("Initialising OpenGL...", Logger::note);

	//InitGLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	Logger::Log("Failed to initalise OpenGL.", Logger::error);
    	return;
	}

	//Window Configs
	glViewport(0, 0, width, height);	//Establish co-ordinate system of window
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //Allow re-sizing

	//Compiling shaders...
	Logger::Log("Compiling shaders...", Logger::note);
	lineShader = Shader("../shaders/lineShader.vs", "../shaders/lineShader.fs");
}

Renderer::~Renderer()
{
	glfwTerminate();
}

/* ----- Render Loop Methods ----- */

void Renderer::SwapBuffers()
{
	//Swap Buffers
    glfwSwapBuffers(window);
}

void Renderer::ClearColor(glm::vec4 color)
{
	//Clear colour
	glClearColor(color.x, color.y, color.z, color.w); //State-setting
	glClear(GL_COLOR_BUFFER_BIT); //State-using
}

/* ----- Draw things! ----- */

void Renderer::DrawLine(Line* line)
{
	//Load shader
	glUseProgram(lineShader.ID);

	//Update color
	int vertexColorLocation = glGetUniformLocation(lineShader.ID, "ourColor");
	glm::vec4 ourLineColor = line->GetColor();
	glUniform4f(vertexColorLocation, ourLineColor.x, ourLineColor.y, ourLineColor.z, ourLineColor.w);
	
    glBindVertexArray(line->GetVAOID());
    glDrawArrays(GL_LINES, 0, 2);
}

/* ----- GLFW CALLBACKS! ----- */

//Callback to allow re-sizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}