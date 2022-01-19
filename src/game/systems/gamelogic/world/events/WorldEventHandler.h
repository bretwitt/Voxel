//
// Created by legon on 6/1/2021.
//

#ifndef VOXEL_WORLDEVENTHANDLER_H
#define VOXEL_WORLDEVENTHANDLER_H


#include "../../../eventhandler/EventHandler.h"
#include "LoadChunkEvent.h"

class WorldEventHandler : public EventHandler {
private:
    static WorldEventHandler * INSTANCE;
public:
    static WorldEventHandler * getInstance();
};


#endif //VOXEL_WORLDEVENTHANDLER_H
