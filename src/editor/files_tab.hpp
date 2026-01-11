#pragma once

#include "imgui.h"
#include <filesystem>
#include <vector>

class Editor;

namespace fs = std::filesystem;

class Files_tab
{
    Editor* editor;

    std::string selected_file;

public:
    Files_tab(Editor* file);
    ~Files_tab();
    void drawFileTree(const fs::path& path);
    void handle();
};