#include <iostream>
#include <Check.h>

class Application : public Check::Engine
{
public:
	Application() 
	{

	}

	~Application()
	{

	}
};

Check::Engine* Check::CreateApplication() {
	return new Application;
}