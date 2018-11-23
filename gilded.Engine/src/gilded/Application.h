#pragma once

#include "Core.h"

namespace gilded {

	class GILDED_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined by client
	Application *CreateApplication();

}

