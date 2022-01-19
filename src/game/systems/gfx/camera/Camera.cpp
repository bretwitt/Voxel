#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <iostream>
#include "Camera.h"

Camera * Camera::INSTANCE = nullptr;
glm::mat4 view(1.0f);


Camera::Camera() {
    globalUp = glm::vec3(0,1,0);
    this->x = 0;
    this->y = 3;
    this->z = 0;
    init();
}

Camera::Camera(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
    init();
}

void Camera::init() {
    projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(80.0f), (float)1200 / (float)800, 0.1f, 100.0f);
    position = glm::vec3(x,y,z);
    front = glm::vec3(0,0,-1);
    globalUp = glm::vec3(0,1,0);
}

float Camera::getX() {
    return position.x;
}
float Camera::getY() {
    return position.y;
}
float Camera::getZ() {
    return position.z;
}

Camera* Camera::getInstance() {
    if(INSTANCE == NULL) {
        INSTANCE = new Camera(0,20,2);
    }
    return INSTANCE;
}

void Camera::cleanup() {
    delete(INSTANCE);
}

void Camera::loop() {

}

void Camera::getMatrices(glm::mat4 & viewmat, glm::mat4 & projectionmat) {
    viewmat = glm::lookAt(position,position+front,globalUp);
    projectionmat = projection;
}

void Camera::rotate(float dyaw, float droll, float dpitch) {
    if(dpitch < -88 || dpitch > 88) {
        return;
    }
    glm::vec3 frontVec;
    frontVec.x = cos(glm::radians(dyaw)) * cos(glm::radians(dpitch));
    frontVec.y = sin(glm::radians(dpitch));
    frontVec.z = sin(glm::radians(dyaw)) * cos(glm::radians(dpitch));
    front = glm::normalize(frontVec);
    right = glm::normalize(glm::cross(front, globalUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
}

void Camera::translate(float dx, float dy, float dz) {
    position += -dx * right;
    position += dz * front;
    position += dy* globalUp;
}
