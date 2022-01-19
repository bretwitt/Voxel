//
// Created by legon on 5/21/2021.
//

#ifndef VOXEL_GAMELOGICSYSTEM_H
#define VOXEL_GAMELOGICSYSTEM_H


#include "../System.h"
#include "world/World.h"
#include "player/PlayerController.h"

class GameLogicSystem : System {

private:
    World world;
    PlayerController controller;
public:
    void preloop() override;
    void postloop() override;
    void cleanup() override;
    void init() override;
    void loop() override;
};


#endif //VOXEL_GAMELOGICSYSTEM_H
