#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace gilded {

	class GILDED_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define GILDED_CORE_ERROR(...) ::gilded::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GILDED_CORE_INFO(...) ::gilded::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GILDED_CORE_TRACE(...) ::gilded::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GILDED_CORE_WARN(...) ::gilded::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GILDED_CORE_FATAL(...) ::gilded::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define GILDED_ERROR(...) ::gilded::Log::GetClientLogger()->error(__VA_ARGS__)
#define GILDED_INFO(...) ::gilded::Log::GetClientLogger()->info(__VA_ARGS__)
#define GILDED_TRACE(...) ::gilded::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GILDED_WARN(...) ::gilded::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GILDED_FATAL(...) ::gilded::Log::GetClientLogger()->fatal(__VA_ARGS__)