#include "Line.h"

#include <glad/glad.h>

RenderObjects::Line::Line()
{
}

RenderObjects::Line::Line(glm::vec2 start, glm::vec2 end, glm::vec4 color)
{
	vertices[0] = start;
	vertices[1] = end;
	lineColor = color;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_DYNAMIC_DRAW); //Assuming these lines will move
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

	//Unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

RenderObjects::Line::~Line() 
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void RenderObjects::Line::SetColor(glm::vec4 color)
{
	lineColor = color;
}

glm::vec4 RenderObjects::Line::GetColor()
{
	return lineColor;
}

void RenderObjects::Line::SetPoints(glm::vec2 start, glm::vec2 end) 
{
	vertices[0] = start;
	vertices[1] = end;

	//send data to buffer again!
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_DYNAMIC_DRAW); //Assuming these lines will move

	//unbind?
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

unsigned int RenderObjects::Line::GetVAOID()
{
	return VBO;
}