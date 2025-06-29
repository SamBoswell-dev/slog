#include <windows.h>

#include <SLog.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SLog logger;
	logger.Init();

	MessageBoxA(NULL, "Check the console!", "Info", MB_OK);
	return 0;
}