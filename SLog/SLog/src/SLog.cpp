#include "SLog.h"

void SLog::Init()
{
	if (AllocConsole())
	{
		FILE* fp;
		freopen_s(&fp, "CONOUT$", "w", stdout);
		freopen_s(&fp, "CONOUT$", "w", stderr);
		freopen_s(&fp, "CONOUT$", "r", stdin);
	}
	
	std::cout << (GetConsoleWindow() != nullptr) << std::endl;
}