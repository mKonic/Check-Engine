#pragma once
#include "Core.h"

#include "Events/Event.h"

#include "Window.h"

namespace Check {
	class CHECK_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// define
	Engine* CreateApplication();
}


