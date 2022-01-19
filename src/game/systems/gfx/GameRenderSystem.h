#ifndef VOXEL_GAMERENDERSYSTEM_H
#define VOXEL_GAMERENDERSYSTEM_H

#include <boost/signals2.hpp>
#include <iostream>
#include "GameRenderSystem.h"
#include "ui/UI.h"
#include "../input/InputHandler.h"
#include "../System.h"
#include "windows/window.h"
#include "camera/Camera.h"
#include "ui/UI.h"

class GameRenderSystem : System {

public:
    Shader shader;
    Window window;
    Camera camera;
    WorldRenderer renderer;
    UI ui;

    void preloop() override;
    void postloop() override;
    void cleanup() override;
    void init() override;
    void loop() override;
    void test();
};


#endif //VOXEL_GAMERENDERSYSTEM_H
