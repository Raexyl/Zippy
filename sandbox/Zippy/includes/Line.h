#ifndef LINE_H
#define LINE_H

#include <glm/glm.hpp>

class Line {
    unsigned int VBO, VAO;
	glm::vec4 lineColor; 	//Works as a uniform
	glm::vec2 vertices[2]; 	//Goes into VBO

public:
	Line();
    Line(glm::vec2 start, glm::vec2 end, glm::vec4 color);
	~Line();

	void SetColor(glm::vec4 color);
	glm::vec4 GetColor(void);
	void SetPoints(glm::vec2 start, glm::vec2 end);

	unsigned int GetVAOID(void);
};

#endif