#pragma once

#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
public:
	/* Application Constructor */
	Application();

	/* Application Deconstructor */
	~Application();

public:
	/* Called to Initialize the Application */
	VOID Initialize();

	/* Game Loop - Cllaed on a loop while the Application is running */
	VOID Update();
}; 