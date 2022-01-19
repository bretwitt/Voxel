#include <iostream>
#include "InputHandler.h"

bool InputHandler::cursorEnabled = false;
GLFWwindow * InputHandler::window = nullptr;
double InputHandler::mouseX;
double InputHandler::mouseY;
InputHandler * InputHandler::INSTANCE = NULL;

InputHandler* InputHandler::getInstance() {
    if(INSTANCE == NULL) { *INSTANCE = InputHandler();  }
    return INSTANCE;
}

void InputHandler::init(GLFWwindow * w) {
    window = w;
    glfwSetCursorPosCallback(window, mouse_callback);
    cursorEnabled = true;
}

void InputHandler::disableCursor() {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    cursorEnabled = false;
}

void InputHandler::enableCursor() {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    cursorEnabled = true;
}

bool InputHandler::getKeyPressed(int key) {
    return glfwGetKey(window,key) == GLFW_PRESS;
}

bool InputHandler::getKeyUp(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

void InputHandler::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if(InputHandler::cursorEnabled) {
        return;
    }
    mouseX = xpos;
    mouseY = ypos;
}

void InputHandler::getMousePosition(double &x, double &y) {
    x = mouseX;
    y = mouseY;
}

void InputHandler::loop() {

}
