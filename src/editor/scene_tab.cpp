#include "scene_tab.hpp"
#include "editor.hpp"

Scene_tab::Scene_tab(Editor* e) : editor(e) {}
Scene_tab::~Scene_tab() {}

void Scene_tab::handle()
{
    ImGui::Begin("Scene");

    if (ImGui::Button("+"))
    {
    }
    ImGui::SameLine();
    if (ImGui::Button("whatever"))
    {
    }
    ImGui::SameLine();

    ImGui::End();
}