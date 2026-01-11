#include "editor.hpp"
#include "argparse.h"
#include "editor/files_tab.hpp"
#include "editor/scene_tab.hpp"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <string>

Editor::Editor(const char* project_dir) : dir(project_dir)
{
    glfwInit();
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(500, 500, project_dir, nullptr, nullptr);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    std::string path = project_dir;
    if (!path.empty() && path.back() != '/')
    {
        path += '/';
    }
    inipath = (path + ".configure/imgui.ini");
    io.IniFilename = inipath.c_str();

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 460 core");

    scene = new Scene_tab(this);
    files = new Files_tab(this);
}
Editor::~Editor()
{
    ImGui::SaveIniSettingsToDisk(ImGui::GetIO().IniFilename);
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    delete scene;
    delete files;
}

void Editor::start()
{
    const double target_fps = 60.0;
    const double frame_time = 1.0 / target_fps;

    while (!glfwWindowShouldClose(window))
    {
        double start = glfwGetTime();
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        DockingHost(this);
        

        scene->handle();
        files->handle();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

        double end = glfwGetTime();
        double elapsed = end - start;
        if (elapsed < frame_time)
            glfwWaitEventsTimeout(frame_time - elapsed);
    }
}