#include "Logger.h"

namespace Logger
{
	void Log(const char* string, level importance)
	{
		switch(importance)
		{
			case note:
				std::cout << "NOTE -- ";
				break;

			case warning:
				std::cout << "WARNING -- ";
				break;

			case error:
				std::cout << "ERROR -- ";
				break;
		}

		std::cout << string << std::endl;
	}
}