#include <windows.h>

#include <SLog.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SLog::SetFormat("[%^N] %^L: %^M");
	SLog::SetFormatEx("[%^N] %^L: %^M | %^V");

	SLog logger("Test Logger");
	logger.Init();

	logger.Trace("Hello world!");

	MessageBoxA(NULL, "Check the console!", "Info", MB_OK);
	return 0;
}