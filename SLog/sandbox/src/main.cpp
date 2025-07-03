#include <SLog.h>

int main()
{
	SLog::SetFormat("[%^N] %^L: %^M");
	SLog::SetFormatEx("[%^N] %^L: %^M | %^V");

	SLog logger("Test logger");
	logger.Init();
	logger.Trace("My message");
	logger.Trace("Health", 41);
}