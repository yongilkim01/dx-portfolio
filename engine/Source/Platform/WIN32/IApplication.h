#pragma once

#define ENTRYAPP(x) IApplication* EntryApplication() {return new x;}

class ENGINE_API IApplication
{
public:
	/* IApplication Constructor */
	IApplication();

	/* IApplication Deconstructor */
	virtual ~IApplication() {};

public:
	/* Called to Initialize the IApplication */
	virtual VOID Initialize() = 0;

	/* Game Loop - Cllaed on a loop while the IApplication is running */
	virtual VOID Update() = 0;
};

IApplication* EntryApplication();