#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <sstream>
#include <iostream>

inline std::string readFileAsString(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << path << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

#endif