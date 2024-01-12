#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

extern Core::App* Core::create_application();

int main(int argc, char** argv) {
	printf("My Engine");
	auto app = Core::create_application();
	app->run();
	delete app;
}

#endif