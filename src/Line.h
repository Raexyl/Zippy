#ifndef LINE_H
#define LINE_H

#include <glm/glm.hpp>

class Line {
    unsigned int shaderProgram;
    unsigned int VBO, VAO;
    glm::vec3 lineColor;
	glm::vec2 vertices[2];

public:
    Line(glm::vec3 start, glm::vec3 end, glm::vec3 color, unsigned int shaderID)
	{

		vertices[0] = start;
		vertices[1] = end;
		lineColor = color;
		shaderProgram = shaderID;
        
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

		//Unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0); 
        glBindVertexArray(0); 
    }

    int Draw() {
        glUseProgram(shaderProgram);

        glBindVertexArray(VAO);
        glDrawArrays(GL_LINES, 0, 2);
        return 1;
    }

    ~Line() {

        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteProgram(shaderProgram);
    }
};

#endif