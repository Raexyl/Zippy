#include "RenderObject.h"

#include <iostream>

RenderObject::RenderObject(void)
{
}

RenderObject::~RenderObject(void)
{
}

void RenderObject::Draw(void)
{
	std::cout << "This method is not overridden by a derivative." << std::endl; 
}

