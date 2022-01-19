//
// Created by legon on 5/23/2021.
//

#ifndef VOXEL_WORLDRENDERER_H
#define VOXEL_WORLDRENDERER_H

#include "../../gamelogic/world/chunk/Chunk.h"
#include "../chunkrenderer/ChunkRenderer.h"
#include "../../eventhandler/Observer.h"

class WorldRenderer : Observer {
private:
    std::vector<ChunkRenderer *> chunkRenderer;
public:
    void init();
    void renderWorld();
    void loadChunk(Chunk chunk);
    void updateChunk(Chunk chunk);
    void unloadChunk(Chunk chunk);
    void unloadChunk(unsigned int chunkID);
    void unloadWorld();
    void cleanup();
    void loop();
    void OnNotify(Event *event);

    void unloadChunk(ChunkRenderer *renderer);
};

#endif //VOXEL_WORLDRENDERER_H
