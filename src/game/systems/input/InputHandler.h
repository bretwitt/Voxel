#ifndef VOXEL_INPUTHANDLER_H
#define VOXEL_INPUTHANDLER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../System.h"

class InputHandler {
private:
    static double mouseX;
    static double mouseY;
    static InputHandler * INSTANCE;
    static bool cursorEnabled;
public:
    static GLFWwindow * window;
    bool getKeyPressed(int key);
    void getMousePosition(double & x, double & y);
    void init(GLFWwindow *w);
    static void mouse_callback(GLFWwindow *window, double xpos, double ypos);
    void disableCursor();
    void enableCursor();
    void loop();
    static InputHandler * getInstance();

    bool getKeyUp(int key);
};


#endif //VOXEL_INPUTHANDLER_H
