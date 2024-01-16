#include "Engine.h"
#include "PerGameSetting.h"

PerGameSetting* PerGameSetting::inst;

PerGameSetting::PerGameSetting()
{
	inst = this;

	wcscpy_s(inst->m_GameName, L"undefined");
	wcscpy_s(inst->m_ShortName, L"undefined");
	wcscpy_s(inst->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
}

PerGameSetting::~PerGameSetting()
{
}
