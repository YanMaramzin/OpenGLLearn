#pragma once
#include <string>

class Logger
{
public:
    Logger();
    ~Logger() = default;

    static void info(const std::string &info);
    static void debug(const std::string &debug);
    static void warning(const std::string &warning);
    static void error(const std::string &error);
    // static void error(const char *error);

};


