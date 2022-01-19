#include "PlayerController.h"
#include "../../input/InputHandler.h"
#include "../../gfx/camera/Camera.h"
#include "../../../VoxelGame.h"

void PlayerController::init() {

}

void PlayerController::loop() {
    handleRotation();
    handleTranslation();
}

void PlayerController::handleTranslation() {
    float dx, dy, dz;
    bool translated = false;
    dx = 0;
    dy = 0;
    dz = 0;
    if(InputHandler::getInstance()->getKeyPressed(GLFW_KEY_W)) {
        dz += 5.0f * VoxelGame::deltaTime;
        translated = true;
    }
    if(InputHandler::getInstance()->getKeyPressed(GLFW_KEY_A)) {
        dx += 5.0f * VoxelGame::deltaTime;
        translated = true;
    }
    if(InputHandler::getInstance()->getKeyPressed(GLFW_KEY_S)) {
        dz -= 5.0f * VoxelGame::deltaTime;
        translated = true;
    }
    if(InputHandler::getInstance()->getKeyPressed(GLFW_KEY_D)) {
        dx -= 5.0f * VoxelGame::deltaTime;
        translated = true;
    }
    if(InputHandler::getInstance()->getKeyPressed(GLFW_KEY_Q)) {
        dy -= 5.0f * VoxelGame::deltaTime;
        translated = true;
    }
    if(InputHandler::getInstance()->getKeyPressed(GLFW_KEY_E)) {
        dy += 5.0f * VoxelGame::deltaTime;
        translated = true;
    }
    if(translated) {
        Camera::getInstance()->translate(dx,dy,dz);
        x = Camera::getInstance()->getX();
        y = Camera::getInstance()->getY();
        z = Camera::getInstance()->getZ();
    }
}

void PlayerController::handleRotation() {
    double x, y;
    InputHandler::getInstance()->getMousePosition(x,y);
    Camera::getInstance()->rotate(x * sensitivity,0,-y * sensitivity);
}
