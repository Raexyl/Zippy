#ifndef CLOSEDLOOP_H
#define CLOSEDLOOP_H

#include <glm/glm.hpp>
namespace RenderObjects{
	class ClosedLoop {
	    unsigned int VBO, VAO;
		glm::vec4 lineColor; 	//Works as a uniform
		std::vector<glm::vec2> vertices; 	//Goes into VBO
	
	public:
		ClosedLoop();
	    ClosedLoop(glm::vec2* points, int numberOfPoints);
		~ClosedLoop();
	
		void SetColor(glm::vec4 color);
		glm::vec4 GetColor(void);
		void SetPoints(glm::vec2* points);
	
		unsigned int GetVAOID(void);
	};
}

#endif