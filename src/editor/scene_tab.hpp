#pragma once

#include "imgui.h"

class Editor;

class Scene_tab
{
    Editor* editor = nullptr;

public:
    Scene_tab(Editor* editor);
    ~Scene_tab();

    void handle();
};