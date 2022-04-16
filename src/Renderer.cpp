#include "Renderer.h"

#include "Logger.h"


Renderer::Renderer(unsigned int width, unsigned int height, const char* windowTitle)
	:m_Width(width), m_Height(height)
{
	Logger::Log("Initalising GLFW...", Logger::logLevel::note);

	//Assign GLFW error callback
	glfwSetErrorCallback(error_callback);

    //InitGLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window
	m_Window = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
	if (m_Window == NULL)
	{
    	Logger::Log("Failed to initialise GLFW window.", Logger::logLevel::error);
    	glfwTerminate();
    	return;
	}
	glfwMakeContextCurrent(m_Window);

	Logger::Log("Initialising OpenGL...",Logger::logLevel::note);

	//InitGLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
    	Logger::Log("Failed to initalise OpenGL.", Logger::logLevel::error);
    	return;
	}

	//Window Configs
	glViewport(0, 0, width, height);	//Establish co-ordinate system of window
	glfwSetFramebufferSizeCallback(m_Window, Renderer::framebuffer_size_callback); //Allow re-sizing

	//Compiling shaders...
	Logger::Log("Compiling shaders...", Logger::logLevel::note);
	int shaderCompilationSuccess = false;

	//LineShader
	m_LineShader = Shader("./Zippy/shaders/lineShader.vs", "./Zippy/shaders/lineShader.fs", &shaderCompilationSuccess);
	int vertexScreenSizeLocation = glGetUniformLocation(m_LineShader.ID, "screenSize");
	glUniform2f(vertexScreenSizeLocation, (float)m_Width, (float)m_Height);
	
	if(!shaderCompilationSuccess) { return; };

	successfulInitialisation = true;
}

Renderer::~Renderer()
{
	glfwTerminate();
}

/* ----- Public *unhidden* method wrappers! ----- */

GLFWwindow* Renderer::GetWindow() { return Get().HiddenGetWindow(); };

glm::vec2 Renderer::GetScreenDimensions() { return Get().HiddenGetScreenDimensions(); };

bool Renderer::InitialisedSuccessfully() { return Get().HiddenInitialisedSuccessfully(); };

void Renderer::SetWindowTitle(const char* string) { Get().HiddenSetWindowTitle(string); };

void Renderer::SetWindowSize(unsigned int width, unsigned int height) { Get().HiddenSetWindowSize(width, height); };

void Renderer::SwapBuffers() { Get().HiddenSwapBuffers(); };

void Renderer::ClearColor(glm::vec4 color) { Get().HiddenClearColor(color); };

void Renderer::DrawLine(RenderObjects::Line* line) { Get().HiddenDrawLine(line); };

void Renderer::DrawLine(glm::vec2 start, glm::vec2 end, glm::vec4 color) { Get().HiddenDrawLine(start, end, color); };

void Renderer::DrawClosedLoop(RenderObjects::ClosedLoop* closedLoop) { Get().HiddenDrawClosedLoop(closedLoop); };

void Renderer::DrawClosedLoop(glm::vec2* points, unsigned int numberOfPoints, glm::vec4 color) { Get().HiddenDrawClosedLoop(points, numberOfPoints, color); };

void Renderer::framebuffer_size_callback(GLFWwindow* window, int width, int height) { Get().hidden_framebuffer_size_callback(window, width, height); };

/* ----- Private *hidden* methods ----- */

GLFWwindow* Renderer::HiddenGetWindow()
{
	return m_Window;
}

glm::vec2 Renderer::HiddenGetScreenDimensions()
{
	return glm::vec2(m_Width, m_Height);
}

bool Renderer::HiddenInitialisedSuccessfully()
{
	return successfulInitialisation;
}

void Renderer::HiddenSetWindowTitle(const char* string)
{
	glfwSetWindowTitle(m_Window, string);
}

void Renderer::HiddenSetWindowSize(unsigned int width, unsigned int height)
{
	glfwSetWindowSize(m_Window, width, height);
}

void Renderer::HiddenSwapBuffers()
{
	//Swap Buffers
    glfwSwapBuffers(m_Window);
}

void Renderer::HiddenClearColor(glm::vec4 color)
{
	//Clear colour
	glClearColor(color.x, color.y, color.z, color.w); //State-setting
	glClear(GL_COLOR_BUFFER_BIT); //State-using
}

void Renderer::HiddenDrawLine(RenderObjects::Line* line)
{
	//Load shader
	glUseProgram(m_LineShader.ID);

	//Uniforms
	//Update color
	int vertexColorLocation = glGetUniformLocation(m_LineShader.ID, "ourColor");
	glm::vec4 ourLineColor = line->GetColor();
	glUniform4f(vertexColorLocation, ourLineColor.x, ourLineColor.y, ourLineColor.z, ourLineColor.w);
	
	//Bind and draw
    glBindVertexArray(line->GetVAOID());
    glDrawArrays(GL_LINES, 0, 2);
}

void Renderer::HiddenDrawLine(glm::vec2 start, glm::vec2 end, glm::vec4 color)
{
	RenderObjects::Line line(start, end, color);
	HiddenDrawLine(&line);
}

void Renderer::HiddenDrawClosedLoop(RenderObjects::ClosedLoop* closedLoop)
{
	//Load shader
	glUseProgram(m_LineShader.ID);

	//Uniforms
	//Update color
	int vertexColorLocation = glGetUniformLocation(m_LineShader.ID, "ourColor");
	glm::vec4 ourLineColor = closedLoop->GetColor();
	glUniform4f(vertexColorLocation, ourLineColor.x, ourLineColor.y, ourLineColor.z, ourLineColor.w);
	
	//Bind and draw
    glBindVertexArray(closedLoop->GetVAOID());
    glDrawArrays(GL_LINE_LOOP, 0, closedLoop->GetNumberOfPoints());
}

void Renderer::HiddenDrawClosedLoop(glm::vec2* points, unsigned int numberOfPoints, glm::vec4 color)
{
	RenderObjects::ClosedLoop loop(points, numberOfPoints, color);
	HiddenDrawClosedLoop(&loop);
}


/* ----- GLFW CALLBACKS! ----- */

//Callback to allow re-sizing (currently disabled)
void Renderer::hidden_framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//Update frame size
    glViewport(0, 0, width, height);
	m_Width = width;
	m_Height = height;

	//Update screen size in shader uniforms!
	int vertexScreenSizeLocation = glGetUniformLocation(m_LineShader.ID, "screenSize");
	glUniform2f(vertexScreenSizeLocation, (float)m_Width, (float)m_Height);
}

//Report errors
void error_callback(int error, const char* description)
{
    Logger::Log(description, Logger::logLevel::error);
}