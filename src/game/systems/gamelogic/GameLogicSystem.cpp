#include "GameLogicSystem.h"

void GameLogicSystem::init() {
    world.init();
}

void GameLogicSystem::preloop() {

}

void GameLogicSystem::loop() {
    controller.loop();
    world.loop(controller.x, controller.y, controller.z);
}

void GameLogicSystem::postloop() {

}

void GameLogicSystem::cleanup() {
    world.cleanup();
}
