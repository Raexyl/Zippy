#ifndef LINE_H
#define LINE_H

#include <glm/glm.hpp>
#include <glad/glad.h>

class Line {
    unsigned int shaderProgram;
    unsigned int VBO, VAO;
	glm::vec4 lineColor; 	//Works as a uniform
	glm::vec2 vertices[2]; 	//Goes into VBO

public:
    Line(glm::vec2 start, glm::vec2 end, glm::vec4 color, unsigned int shaderID);
	~Line();

    int Draw();
	void SetColor(glm::vec4 color);
	void SetPoints(glm::vec2 start, glm::vec2 end);

private:
		int UpdateColor(glm::vec4 color);
};

#endif