#pragma once
#include "Core.h"

namespace Check {
	class CHECK_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void Run();
	};

	// define
	Engine* CreateApplication();
}


