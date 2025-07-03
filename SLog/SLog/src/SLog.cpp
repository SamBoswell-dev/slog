#include "SLog.h"

std::string SLog::m_Format = "";
std::string SLog::m_FormatEx = "";


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