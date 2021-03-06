#pragma once

#ifdef GILDED_PLATFORM_WINDOWS

extern gilded::Application* gilded::CreateApplication();

int main(int argc, char** argv)
{
	gilded::Log::Init();

	auto app = gilded::CreateApplication();
	app->Run();
	delete app;
}

#endif