#include "Engine.h"
#include <fstream>
#include <ShlObj.h>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}

/* Print to log file with option */
VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	//MessageBox(0, buf, 0, 0);

	OutputDebugString(buf);

	// Example file location = %AppData%/Game/Log/Game03052021194056.log

	std::wfstream outfile;

	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open())
	{
		std::wstring s = buf;
		outfile << L"[" << Time::GetDateTimeString() << L"] " << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else 
	{
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
}

/* Get and Create Log Directory in AppData/$ProjectName/Log */
std::wstring Logger::LogDirectory()
{
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, PerGameSetting::GameName());
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Logger::LogFile()
{
	WCHAR File[1024];
	wcscpy_s(File, PerGameSetting::GameName());
	wcscpy_s(File, PerGameSetting::BootTime());
	wcscat_s(File, L".log");
	return File;
}
