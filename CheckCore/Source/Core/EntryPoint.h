#pragma once

extern Check::Engine* Check::CreateApplication();

int main() {
	Check::Log::Init();
	CE_CORE_WARN("Initialized log!");
	CE_INFO ("Hello!");

	auto app = Check::CreateApplication();
	app->Run();
	delete app;
}
