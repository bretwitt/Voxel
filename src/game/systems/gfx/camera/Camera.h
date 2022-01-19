//
// Created by legon on 5/21/2021.
//

#ifndef VOXEL_CAMERA_H
#define VOXEL_CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Camera {
private:
    float x, y, z;
    static Camera * INSTANCE;
    glm::mat4 projection;
    glm::vec3 front;
    glm::vec3 right;
    glm::vec3 globalUp;
    glm::vec3 position;

public:
    static Camera * getInstance();
    Camera(float x, float y, float z);
    Camera();
    void loop();
    void translate(float dx, float dy, float dz);
    void getMatrices(glm::mat4 &view, glm::mat4 &projection);

    static void cleanup();

    float getX();

    float getZ();

    float getY();

    void rotate(float dyaw, float droll, float dpitch);

    void init();
};


#endif //VOXEL_CAMERA_H
