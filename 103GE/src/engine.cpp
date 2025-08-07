#define GLM_ENABLE_EXPERIMENTAL

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "engine.hpp"

bool shouldClose = false;
GLFWwindow *window;
void init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "103GE", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGL();
}

void update(float delta) {}

void run()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    float lastCheck = glfwGetTime();
    while (!shouldClose)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        float now = glfwGetTime();
        float delta = lastCheck - now;
        lastCheck = now;
        update(delta);
        glfwPollEvents();
        glfwSwapBuffers(window);
        shouldClose = glfwWindowShouldClose(window);
    }
}

void destroy()
{
    glfwTerminate();
    glfwDestroyWindow(window);
}