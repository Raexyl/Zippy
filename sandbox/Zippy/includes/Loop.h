#ifndef LOOP_H
#define LOOP_H

#include <glm/glm.hpp>
#include <vector>

namespace RenderObjects{
	class Loop {
	    unsigned int VBO, VAO;
		glm::vec4 lineColor; 	//Works as a uniform
		glm::vec2* vertices; 	//Goes into VBO
		unsigned int noOfPoints;
	
	public:
		Loop();
	    Loop(glm::vec2* points, unsigned int numberOfPoints, glm::vec4 color);
		~Loop();
	
		void SetColor(glm::vec4 color);
		glm::vec4 GetColor(void);
		void SetPoints(glm::vec2* points, unsigned int numberOfPoints);
		unsigned int GetNumberOfPoints(void);
	
		unsigned int GetVAOID(void);
	};
}

#endif