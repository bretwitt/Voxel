#ifndef VOXEL_UI_H
#define VOXEL_UI_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class UI {
public:
    void init(GLFWwindow * glfWwindow);
    void preloop();
    void postloop();
    void cleanup();

    void loop();
};


#endif //VOXEL_UI_H
