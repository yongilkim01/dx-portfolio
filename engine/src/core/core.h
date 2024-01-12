#pragma once

#include "header.h"

namespace Core {

	class ENGINE_API App {
	public:
		App();
		~App();

	public:
		void run();
	};

	App* create_application();

}
