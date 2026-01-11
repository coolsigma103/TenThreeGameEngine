#pragma once

// clang-format off
#include<glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include <filesystem>
#include <fstream>
#include <vector>

namespace fs = std::filesystem;

class Project_manager
{
    GLFWwindow* window;
    bool close = false;

    fs::path user_data_dir;

public:
    Project_manager(const char*& project);
    ~Project_manager();

    void add_project(fs::path path);
    void handle_user_data();

    struct Project
    {
        std::string name;
        const char* dir;
        std::string description;
    };

    std::vector<Project> project;
};

inline fs::path getUserDataFile()
{
    fs::path baseConfig;

#if defined(_WIN32) || defined(_WIN64)
    const char* appdata = std::getenv("APPDATA");
    if (appdata)
        baseConfig = fs::path(appdata);
    else if (const char* userProfile = std::getenv("USERPROFILE"))
        baseConfig = fs::path(userProfile) / "AppData" / "Roaming";
#elif defined(__APPLE__)
    if (const char* home = std::getenv("HOME"))
        baseConfig = fs::path(home) / "Library" / "Application Support";
#elif defined(__linux__)
    if (const char* home = std::getenv("HOME"))
        baseConfig = fs::path(home) / ".config";
#else
    baseConfig = fs::current_path(); // fallback
#endif

    // Ensure 103GE folder exists
    fs::path userDataDir = baseConfig / "103GE";
    if (!fs::exists(userDataDir))
        fs::create_directories(userDataDir);

    // userdata.txt path
    fs::path userDataFile = userDataDir / "userdata.txt";

    // Create file if it doesn't exist
    if (!fs::exists(userDataFile))
    {
        std::ofstream turipipipip(userDataFile); // creates empty file
    }

    return userDataFile;
}
