#ifndef CLOSEDLOOP_H
#define CLOSEDLOOP_H

#include <glm/glm.hpp>
#include <vector>

namespace RenderObjects{
	class ClosedLoop {
	    unsigned int VBO, VAO;
		glm::vec4 lineColor; 	//Works as a uniform
		glm::vec2* vertices; 	//Goes into VBO
		unsigned int noOfPoints;
	
	public:
		ClosedLoop();
	    ClosedLoop(glm::vec2* points, unsigned int numberOfPoints, glm::vec4 color);
		~ClosedLoop();
	
		void SetColor(glm::vec4 color);
		glm::vec4 GetColor(void);
		void SetPoints(glm::vec2* points, unsigned int numberOfPoints);
		unsigned int GetNumberOfPoints(void);
	
		unsigned int GetVAOID(void);
	};
}

#endif