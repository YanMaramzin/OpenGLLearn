#include <iostream>
#include "logger.h"

Logger::Logger() = default;

void Logger::info(const std::string &info)
{
    std::cout << "\033[1;97mINFO: " + info + "\033[0m\n";
}

void Logger::debug(const std::string &debug)
{
    std::cout << "\033[1;34mDEBUG: " + debug + "\033[0m\n";
}

void Logger::warning(const std::string &warning)
{
    std::cout << "\033[1;33mWARNING: " + warning + "\033[0m\n";
}

void Logger::error(const std::string &error)
{
    std::cout << "\033[1;31mERROR: " + error + "\033[0m\n";
}

// void Logger::error(const char *error)
// {
//     std::cout << error;
// }


