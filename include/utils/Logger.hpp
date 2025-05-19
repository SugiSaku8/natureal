#pragma once

#include <string>

namespace Natureal {

class Logger {
public:
    enum class LogLevel {
        Debug,
        Info,
        Warning,
        Error
    };

    static Logger& getInstance();
    void log(LogLevel level, const std::string& message);

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

// Convenience macros
#define LOG_DEBUG(msg) Natureal::Logger::getInstance().log(Natureal::Logger::LogLevel::Debug, msg)
#define LOG_INFO(msg) Natureal::Logger::getInstance().log(Natureal::Logger::LogLevel::Info, msg)
#define LOG_WARNING(msg) Natureal::Logger::getInstance().log(Natureal::Logger::LogLevel::Warning, msg)
#define LOG_ERROR(msg) Natureal::Logger::getInstance().log(Natureal::Logger::LogLevel::Error, msg)

} // namespace Natureal 