#include "Line.h"

Line::Line(glm::vec2 start, glm::vec2 end, glm::vec4 color, unsigned int shaderID)
{
	vertices[0] = start;
	vertices[1] = end;
	lineColor = color;
	shaderProgram = shaderID;
       
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

Line::~Line() 
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
}

int Line::Draw() 
{
    glUseProgram(shaderProgram);
	UpdateColor(lineColor);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
    return 1;
}

void Line::SetColor(glm::vec4 color)
{
	lineColor = color;
}

void Line::SetPoints(glm::vec2 start, glm::vec2 end) 
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
	
int Line::UpdateColor(glm::vec4 color)
{
	int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	glUniform4f(vertexColorLocation, lineColor.x, lineColor.y, lineColor.z, lineColor.w);
	return 1;
}