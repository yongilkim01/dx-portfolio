#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application);

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::SetupPerGameSetting()
{
	/* Set the per game setting */
	PerGameSetting::SetGameName(IDS_PERGAMENAME);
	PerGameSetting::SetShortName(IDS_SHORTNAME);
	PerGameSetting::SetMainIcon(IDI_MAINICON);
}

VOID Application::Initialize()
{
	Logger::PrintDebugSeperartor();
	Logger::PrintLog(L"Application Starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSetting::GameName());
	Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeperartor();

	Logger::StartMTail();
}

VOID Application::Update()
{
	MessageBox(0, L" Loop ", 0, 0);
}
