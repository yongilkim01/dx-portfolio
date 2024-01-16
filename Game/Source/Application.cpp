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
	Logger::PrintLog(L"I have Loaded Up %s, Thankyou", L"Game project");
}

VOID Application::Update()
{
	MessageBox(0, L"Loop", 0, 0);
}
