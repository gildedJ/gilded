#pragma once

#ifdef GILDED_PLATFORM_WINDOWS
	#ifdef GILDED_BUILD_DLL
		#define GILDED_API __declspec(dllexport)
	#else
		#define GILDED_API __declspec(dllimport)
	#endif
#else
	#error Gilded Engine only supports Windows at the moment!
#endif