#pragma once

#ifdef CE_PLATFORM_WINDOWS
	#ifdef CE_BUILD_DLL
		#define CHECK_API __declspec(dllexport)
	#else
		#define CHECK_API __declspec(dllimport)
	#endif
#else 
	#error Only windows support for now :)
#endif

