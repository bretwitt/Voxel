#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
#include "../../../VoxelGame.h"


void Window::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window_handle = glfwCreateWindow(1200,800,"Title",NULL,NULL);
    glfwMakeContextCurrent(window_handle);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    glEnable(GL_DEPTH_TEST);
}

void Window::preloop() {
    int display_w, display_h;
    glfwGetFramebufferSize(window_handle, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::loop() {
    if(focus && InputHandler::getInstance()->getKeyPressed(GLFW_KEY_ESCAPE)) {
        InputHandler::getInstance()->enableCursor();
        focus = false;
    }
    if(!focus && glfwGetMouseButton(this->window_handle, GLFW_MOUSE_BUTTON_LEFT)) {
        InputHandler::getInstance()->disableCursor();
        focus = true;
    }
    if(!glfwWindowShouldClose(window_handle)){
        glfwPollEvents();
    }
    else
    {
        close();
    }
}

void Window::postloop() {
    glfwSwapBuffers(window_handle);
}

void Window::close() {
    VoxelGame::close();
}

void Window::cleanup() {
    glfwDestroyWindow(window_handle);
    glfwTerminate();
}
