#include "files_tab.hpp"
#include "editor/editor.hpp"
#include "imgui.h"

Files_tab::Files_tab(Editor* e) : editor(e) {}
Files_tab::~Files_tab() {}

void Files_tab::drawFileTree(const fs::path& path)
{
    std::vector<fs::directory_entry> folders;
    std::vector<fs::directory_entry> files;

    // First, separate folders and files
    for (const auto& entry : fs::directory_iterator(path))
    {
        std::string name = entry.path().filename().string();

        if (entry.is_directory())
        {
            if (name == ".configure")
                continue;
            folders.push_back(entry);
        }
        else
        {
            if (entry.path().extension().string() == ".import")
                files.push_back(entry);
        }
    }

    // Draw folders first
    for (const auto& entry : folders)
    {
        const auto& p = entry.path();
        std::string name = p.filename().string();

        if (ImGui::TreeNode(name.c_str()))
        {
            drawFileTree(p); // recursive
            ImGui::TreePop();
        }

        // Right-click on folder
        if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
        {
            selected_file = p.string();
            ImGui::OpenPopup(("FileContextMenu##" + p.string()).c_str());
        }

        if (ImGui::BeginPopup(("FileContextMenu##" + p.string()).c_str()))
        {
            if (ImGui::BeginMenu("New"))
            {
                if (ImGui::MenuItem("Folder"))
                {
                }
                ImGui::EndMenu();
            }
            if (ImGui::MenuItem("Open"))
            {
            }
            if (ImGui::MenuItem("Delete"))
            {
            }
            ImGui::EndPopup();
        }
    }

    // Draw files after folders
    for (const auto& entry : files)
    {
        const auto& p = entry.path();
        std::string name = p.filename().string();

        if (ImGui::Selectable(name.c_str()))
            selected_file = p.string();

        // Right-click on file
        if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
        {
            selected_file = p.string();
            ImGui::OpenPopup("FileContextMenu");
        }

        if (ImGui::BeginPopup("FileContextMenu"))
        {
            if (ImGui::MenuItem("Open"))
            {
            }
            if (ImGui::MenuItem("Delete"))
            {
            }
            ImGui::EndPopup();
        }
    }
}

void Files_tab::handle()
{
    ImGui::Begin("Files");

    if (ImGui::TreeNode("res://"))
    {
        drawFileTree(editor->getDir());
        ImGui::TreePop();
    }
    ImGui::End();
}