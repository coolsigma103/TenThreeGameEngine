#include "project_manager.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Project_manager::Project_manager(const char*& project)
{
    user_data_dir = getUserDataFile();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(700, 500, "Godot Engine", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    io.IniFilename = nullptr;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    ImGuiWindowFlags window_flags =
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoSavedSettings;

    const double target_fps = 60.0;
    const double frame_time = 1.0 / target_fps;

    while (!glfwWindowShouldClose(window))
    {
        double start = glfwGetTime();
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

        static int tab = 0;

        ImGui::Begin("Project Manager", nullptr, window_flags);

        ImGui::Begin("Options");
        ImGui::RadioButton("Projects", &tab, 0);
        ImGui::RadioButton("Templates", &tab, 1);
        ImGui::End();

        if (tab == 0)
        {
        }

        ImGui::End();

        ImGui::PopStyleVar(3);

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
Project_manager::~Project_manager() {}

void Project_manager::handle_user_data()
{
    std::ifstream file(user_data_dir);
    std::string currentProject;
    while (std::getline(user_data_dir, currentProject))
    {
    }
}