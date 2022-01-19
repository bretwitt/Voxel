//
// Created by legon on 5/31/2021.
//

#ifndef VOXEL_LOADCHUNKEVENT_H
#define VOXEL_LOADCHUNKEVENT_H


#include "../../../eventhandler/Event.h"
#include "../chunk/Chunk.h"

class LoadChunkEvent : public Event {
public:
    Chunk* chunk;
    explicit LoadChunkEvent(Chunk *chunk);
};


#endif //VOXEL_LOADCHUNKEVENT_H
