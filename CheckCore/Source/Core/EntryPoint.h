#pragma once

extern Check::Engine* Check::CreateApplication();

int main() {
	auto app = Check::CreateApplication();
	app->Run();
	delete app;
}
