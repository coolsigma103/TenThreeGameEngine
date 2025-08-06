#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <GLFW/glfw3.h>
#include "input.hpp"
#include "maths/vector.hpp"

class Input
{
    static bool keys[KEY_LAST + 1]; 
    static bool mouseButtons[MOUSE_BUTTON_LAST + 1];
    static vector2 mousePosition;
    static vector2 mouseDelta;
    static bool joysticks[JOYSTICK_LAST + 1];
    static bool gamepadButtons[GAMEPAD_BUTTON_LAST + 1];
    public:

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key >= 0 && key <= KEY_LAST)
        {
            if (action == GLFW_PRESS)
                keys[key] = true;
            else if (action == GLFW_RELEASE)
                keys[key] = false;
        }
    }

    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        if (button >= 0 && button <= MOUSE_BUTTON_LAST)
        {
            if (action == GLFW_PRESS)
                mouseButtons[button] = true;
            else if (action == GLFW_RELEASE)
                mouseButtons[button] = false;
        }
    }

    static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
    {
        mouseDelta.x = static_cast<float>(xpos) - mousePosition.x;
        mouseDelta.y = static_cast<float>(ypos) - mousePosition.y;
        mousePosition.x = static_cast<float>(xpos);
        mousePosition.y = static_cast<float>(ypos);
    }

    static void joystickCallback(int jid, int event)
    {
        if (jid >= 0 && jid <= JOYSTICK_LAST)
        {
            if (event == GLFW_CONNECTED)
                joysticks[jid] = true;
            else if (event == GLFW_DISCONNECTED)
                joysticks[jid] = false;
        }
    }

    static void gamepadButtonCallback(int jid, int button, int action)
    {
        if (jid >= 0 && jid <= JOYSTICK_LAST && button >= 0 && button <= GAMEPAD_BUTTON_LAST)
        {
            if (action == GLFW_PRESS)
                gamepadButtons[button] = true;
            else if (action == GLFW_RELEASE)
                gamepadButtons[button] = false;
        }
    }

    static bool isKeyPressed(int key)
    {
        return keys[key];
    }

    static bool isMouseButtonPressed(int button)
    {
        return mouseButtons[button];
    }

    static vector2 getMousePosition()
    {
        return mousePosition;
    }

    static vector2 getMouseDelta()
    {
        return mouseDelta;
    }

    static bool isJoystickConnected(int joystick)
    {
        return joysticks[joystick];
    }

    static bool isGamepadButtonPressed(int button)
    {
        return gamepadButtons[button];
    }

    static void resetMouseDelta()
    {
        mouseDelta = vector2(0.0f, 0.0f);
    }

    static void reset()
    {
        init();
        resetMouseDelta();
    }

    static void init()
    {
        for (int i = 0; i <= KEY_LAST; ++i)
            keys[i] = false;

        for (int i = 0; i <= MOUSE_BUTTON_LAST; ++i)
            mouseButtons[i] = false;

        mousePosition = vector2(0.0f, 0.0f);
        mouseDelta = vector2(0.0f, 0.0f);

        for (int i = 0; i <= JOYSTICK_LAST; ++i)
            joysticks[i] = false;

        for (int i = 0; i <= GAMEPAD_BUTTON_LAST; ++i)
            gamepadButtons[i] = false;

        glfwSetKeyCallback(glfwGetCurrentContext(), keyCallback);
        glfwSetMouseButtonCallback(glfwGetCurrentContext(), mouseButtonCallback);
        glfwSetCursorPosCallback(glfwGetCurrentContext(), cursorPositionCallback);
        glfwSetJoystickCallback(joystickCallback);
    }
};

#endif