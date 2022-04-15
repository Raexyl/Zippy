#include "ClosedLoop.h"

#include <glad/glad.h>

RenderObjects::ClosedLoop::ClosedLoop()
{
}

RenderObjects::ClosedLoop::ClosedLoop(glm::vec2* points, unsigned int numberOfPoints)
{
	vertices = points;
	noOfPoints = numberOfPoints;
	lineColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(*vertices), vertices, GL_DYNAMIC_DRAW); //Assuming these lines will move
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	//Unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

RenderObjects::ClosedLoop::~ClosedLoop() 
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void RenderObjects::ClosedLoop::SetColor(glm::vec4 color)
{
	lineColor = color;
}

glm::vec4 RenderObjects::ClosedLoop::GetColor(void)
{
	return lineColor;
}

void RenderObjects::ClosedLoop::SetPoints(glm::vec2* points, unsigned int numberOfPoints) 
{
	vertices = points;
	noOfPoints = numberOfPoints;

	//send data to buffer again!
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(*vertices), vertices, GL_DYNAMIC_DRAW); //Assuming these lines will move

	//unbind?
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

unsigned int RenderObjects::ClosedLoop::GetNumberOfPoints()
{
	return noOfPoints;
}

unsigned int RenderObjects::ClosedLoop::GetVAOID()
{
	return VBO;
}