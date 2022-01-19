
#include "GameRenderSystem.h"
#include "../eventhandler/EventHandler.h"

using namespace boost::signals2;

void GameRenderSystem::init() {
    window = Window();
    ui = UI();
    renderer = WorldRenderer();

    window.init();
    ui.init(window.window_handle);
    renderer.init();
}

void GameRenderSystem::preloop() {
    window.preloop();
    ui.preloop();
}

void GameRenderSystem::loop() {
    Camera::getInstance()->loop();
    InputHandler::getInstance()->loop();
    window.loop();
    ui.loop();
    renderer.loop();
    renderer.renderWorld();
}

void GameRenderSystem::postloop() {
    ui.postloop();
    window.postloop();
}

void GameRenderSystem::cleanup() {
    Camera::cleanup();
    renderer.cleanup();
    ui.cleanup();
    window.cleanup();
}
