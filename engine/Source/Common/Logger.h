#pragma once

#include <string>

class ENGINE_API Logger
{
public:
	Logger();
	~Logger();

public:
	static Logger* Instance() { return inst; }

public:
	/* Print to log file */
	static VOID PrintLog(const WCHAR* fmt, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	/* Print a line of '-' char's */
	static VOID PrintDebugSeperartor();

	/* Check to see if MTail is already Running */
	static BOOL IsMTailRunning();

	/* Start MTail Application */
	static VOID StartMTail();

private:
	static Logger* inst;

};