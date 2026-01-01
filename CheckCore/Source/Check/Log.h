#pragma once



#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

// Enable formatting for any type with a ToString() method
template <typename T>
struct fmt::formatter<T, std::enable_if_t<std::is_member_function_pointer_v<decltype(&T::ToString)>, char>>
	: fmt::formatter<std::string> {
	auto format(const T& obj, fmt::format_context& ctx) const {
		return fmt::formatter<std::string>::format(obj.ToString(), ctx);
	}
};

namespace Check {
	class CHECK_API Log
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

// Core log macros
#define CE_CORE_TRACE(...)   ::Check::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CE_CORE_INFO(...)    ::Check::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CE_CORE_WARN(...)    ::Check::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CE_CORE_ERROR(...)   ::Check::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CE_CORE_CRITICAL(...)   ::Check::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Core log macros
#define CE_TRACE(...) ::Check::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CE_INFO(...)  ::Check::Log::GetClientLogger()->info(__VA_ARGS__)
#define CE_WARN(...)  ::Check::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CE_ERROR(...) ::Check::Log::GetClientLogger()->error(__VA_ARGS__)
#define CE_CRITICAL(...) ::Check::Log::GetClientLogger()->critical(__VA_ARGS__)