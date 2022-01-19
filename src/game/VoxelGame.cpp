#include <iostream>
#include "VoxelGame.h"

double VoxelGame::deltaTime = 0;
VoxelGame * VoxelGame::INSTANCE = NULL;

VoxelGame * VoxelGame::getInstance() {
    return INSTANCE;
}

void VoxelGame::init() {
    INSTANCE = this;
    gameLogicSystem = GameLogicSystem();
    renderSystem = GameRenderSystem();
    gameLogicSystem.init();
    renderSystem.init();
    InputHandler::getInstance()->init(renderSystem.window.window_handle);

    shouldExit = false;
    time = glfwGetTime();
    while(!shouldExit)
    {
        loop();
    }
}

void VoxelGame::loop() {
    time = glfwGetTime();
    gameLogicSystem.preloop();
    renderSystem.preloop();
    gameLogicSystem.loop();
    renderSystem.loop();
    gameLogicSystem.postloop();
    renderSystem.postloop();
    deltaTime = glfwGetTime() - time;
}

void VoxelGame::close() {
    getInstance()->gameLogicSystem.cleanup();
    getInstance()->renderSystem.cleanup();
    exit(0);
}