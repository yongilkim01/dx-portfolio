#include "Engine.h"
#include "Logger.h"

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}
