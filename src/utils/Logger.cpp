#include "utils/Logger.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

namespace Natureal {

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(LogLevel level, const std::string& message) {
    std::stringstream ss;
    
    // Add timestamp
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S") << " ";

    // Add log level
    switch (level) {
        case LogLevel::Debug:
            ss << "[DEBUG] ";
            break;
        case LogLevel::Info:
            ss << "[INFO] ";
            break;
        case LogLevel::Warning:
            ss << "[WARNING] ";
            break;
        case LogLevel::Error:
            ss << "[ERROR] ";
            break;
    }

    // Add message
    ss << message;

    // Output to console
    std::cout << ss.str() << std::endl;
}

void Logger::debug(const std::string& message) {
    log(LogLevel::Debug, message);
}

void Logger::info(const std::string& message) {
    log(LogLevel::Info, message);
}

void Logger::warning(const std::string& message) {
    log(LogLevel::Warning, message);
}

void Logger::error(const std::string& message) {
    log(LogLevel::Error, message);
}

} // namespace Natureal 