#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

namespace Logger
{
	enum level 
	{
		note, warning, error
	};

	void Log(const char* string, level importance);
};

#endif