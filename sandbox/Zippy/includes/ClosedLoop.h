#ifndef CLOSEDLOOP_H
#define CLOSEDLOOP_H

#include <glm/glm.hpp>
#include <vector>

namespace RenderObjects{
	class ClosedLoop {
	    unsigned int VBO, VAO;
		glm::vec4 lineColor; 	//Works as a uniform
		std::vector<glm::vec2> vertices; 	//Goes into VBO
	
	public:
		ClosedLoop();
	    ClosedLoop(std::vector<glm::vec2> points);
		~ClosedLoop();
	
		void SetColor(glm::vec4 color);
		glm::vec4 GetColor(void);
		void SetPoints(std::vector<glm::vec2> points);
	
		unsigned int GetVAOID(void);
	};
}

#endif