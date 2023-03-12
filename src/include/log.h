#pragma once

#include <unistd.h>
#include <fcntl.h>
#include <string>

#define DF_LOGLEVEL LogLevel::Debug
#define DF_LOGFILE "/storage/emulated/0/Android/FAS/FasLog.txt"
#define DEBUG(x) Log::write(LogLevel::Debug, x)
#define INFO(x) Log::write(LogLevel::Info, x)
#define WARN(x) Log::write(LogLevel::Warning, x)
#define ERROR(x) Log::write(LogLevel::Error, x)

enum class LogLevel
{
    Debug,
    Info,
    Warning,
    Error
};

class Log
{
public:
    static void write(LogLevel level, const std::string& message);
private:
    static const LogLevel currentLevel = DF_LOGLEVEL;
    static const char *levelToString(LogLevel level);
};