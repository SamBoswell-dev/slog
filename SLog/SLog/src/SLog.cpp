#include "SLog.h"

void SLog::Init()
{
	std::cout << (GetConsoleWindow() == nullptr) << std::endl;
}

void SLog::HasConsole() const
{
	/*if (GetConsoleWindow() == nullptr)
	{

	}*/

	AllocConsole();
}