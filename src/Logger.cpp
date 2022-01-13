#include "Logger.h"

namespace Logger
{
	namespace
	{
		logLevel filter = note;
	}
	
	void Log(const char* string, logLevel importance)
	{
		switch(importance)
		{
			case note:
				if(filter != note) { return; };
				std::cout << "NOTE -- ";
				break;
			case warning:
				if(filter == error) { return; };
				std::cout << "WARNING -- ";
				break;
			case error:
				std::cout << "ERROR -- ";
				break;
		}
		std::cout << string << std::endl;
	}

	void SetLogLevel(logLevel level)
	{
		filter = level;
	}
}