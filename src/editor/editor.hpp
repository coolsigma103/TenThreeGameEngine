#pragma once

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include "editor/files_tab.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "scene_tab.hpp"
#include <argparse/argparse.h>
#include <filesystem>
#include <iostream>

static std::string rename_buffer;
static std::string rename_target;

class Editor
{
    GLFWwindow* window;
    Scene_tab* scene = nullptr;
    Files_tab* files;

    const char* dir;
    std::string inipath;

public:
    Editor(const char* project_dir);
    ~Editor();
    void start();
    const char* getDir() { return dir; }
};

inline void DockingHost(Editor* editor)
{
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGui::SetNextWindowViewport(viewport->ID);

    // Window flags for invisible dockspace
    ImGuiWindowFlags window_flags =
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus |
        ImGuiWindowFlags_NoBackground |   // no background
        ImGuiWindowFlags_NoDecoration |   // removes borders and title
        ImGuiWindowFlags_NoSavedSettings; // optional

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("DockSpaceHost", nullptr, window_flags);

    ImGui::Button("Hi");

    // Dockspace
    ImGuiID dockspace_id = ImGui::GetID("InvisibleDockSpace");
    ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f),
                     ImGuiDockNodeFlags_PassthruCentralNode); // make background
                                                              // click-through

    ImGui::End();

    ImGui::PopStyleVar(3);
}