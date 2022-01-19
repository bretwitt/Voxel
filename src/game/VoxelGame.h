#ifndef VOXEL_VOXELGAME_H
#define VOXEL_VOXELGAME_H


#include "systems/gamelogic/GameLogicSystem.h"
#include "systems/gfx/GameRenderSystem.h"
#include "systems/input/InputHandler.h"

class VoxelGame {
private:
    static VoxelGame * INSTANCE;
public:
    GameLogicSystem gameLogicSystem;
    GameRenderSystem renderSystem;
    InputHandler input;
    double time = 0;
    bool shouldExit;
    void init();
    void loop();
    static void close();
    static double deltaTime;
    static VoxelGame * getInstance();
};


#endif //VOXEL_VOXELGAME_H
