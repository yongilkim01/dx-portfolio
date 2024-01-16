#include "Engine.h"
#include <fstream>
#include <ShlObj.h>
#include <cstdio>
#include <TlHelp32.h>

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

/* Print seperator line without time stamp */
VOID Logger::PrintDebugSeperartor()
{
	std::wstring s = L"\n----------------------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outFile;
	outFile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outFile.is_open())
	{
		outFile << s;
		outFile.close();
	}
	else
	{
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

/* Check to MTail is already open */
BOOL Logger::IsMTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
	{
		while (Process32Next(snapshot, &entry))
		{
			if (!_wcsicmp(entry.szExeFile, L"mTail.exe"))
			{
				exists = true;
			}
		}
	}

	CloseHandle(snapshot);
	return exists;
}

/* Start MTail Application */
VOID Logger::StartMTail()
{
	if (IsMTailRunning())
	{
		Logger::PrintLog(L"MTail failed : Already Running\n");
		return;
	}
	
	Logger::PrintLog(L"Start MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTail.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}