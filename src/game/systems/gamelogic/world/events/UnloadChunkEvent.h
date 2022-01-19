//
// Created by legon on 6/1/2021.
//

#ifndef VOXEL_UNLOADCHUNKEVENT_H
#define VOXEL_UNLOADCHUNKEVENT_H


#include "../../../eventhandler/Event.h"
#include "../chunk/Chunk.h"

class UnloadChunkEvent : public Event {
public:
    explicit UnloadChunkEvent(Chunk *chunk);
    Chunk* chunk;
};



#endif //VOXEL_UNLOADCHUNKEVENT_H
