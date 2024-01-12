#include <engine.h>

class Sandbox : public Core::App {
public:
	Sandbox()
	{

	}

	~Sandbox() 
	{

	}
};

Core::App* Core::create_application() {
	return new Sandbox();
}