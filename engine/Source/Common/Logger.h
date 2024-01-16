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

private:
	static Logger* inst;

};