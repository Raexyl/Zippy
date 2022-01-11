//LearnOpenGL Tutorial follow-along (see readme)

//Logging (& debugging)
#include <iostream>

//Graphics
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//In-project files
#include "Shader.h"

//Types of rendering
#include "Line.h"

//Callback to allow re-sizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

//Process Inputs
void ProcessInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
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

	//Rectangle Verts
	float vertices[] = {
    	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,// top right
    	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,// bottom right
    	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,// bottom left
    	-0.5f,  0.5f, 0.0f,   0.5f, 0.5f, 0.5f// top left 
	};

	//Verts in order
	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	//We need a VAO
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//Creating GL Buffer Object
	unsigned int VBO; //OpenGL ID
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//And an EBO
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Tell OpenGL how our vertices are formatted
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
	glEnableVertexAttribArray(1); 

	//Compiling shaders...
	std::cout << "Compiling Shaders..." << std::endl;
	Shader shader("../shaders/shader.vs", "../shaders/shader.fs");
	Shader lineShader("../shaders/lineShader.vs", "../shaders/lineShader.fs");

	//Line test
	Line myLine(glm::vec2(0.6f, 0.5f), glm::vec2(-0.4f, -0.8f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f), lineShader.ID);

	//Main render loop
	while(!glfwWindowShouldClose(window))
	{
		//Input
		ProcessInput(window);

		//Clear colour
		glClearColor(0.2f, 0.4f, 0.6f, 0.5f); //State-setting
		glClear(GL_COLOR_BUFFER_BIT); //State-using

		//Render
		//Draw Rectangle
		shader.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		myLine.Draw();
		float value = sin(glfwGetTime());
		float valuecos = cos(glfwGetTime());
		myLine.SetPoints(glm::vec2(0.0f, 0.0f), glm::vec2(value, valuecos));

		//Swap Buffers, Check events
    	glfwSwapBuffers(window);
    	glfwPollEvents();    
	}

	glfwTerminate(); //Exit cleanly (de-allocating memory?)
    return 0;
}