#pragma once

class ENGINE_API Logger
{
public:
	Logger();
	~Logger();

public:
	static Logger* Instance() { return inst; }

private:
	static Logger* inst;

};