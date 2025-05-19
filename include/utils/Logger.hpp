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
    void debug(const std::string& message);
    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

} // namespace Natureal 