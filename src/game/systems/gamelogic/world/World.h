#ifndef VOXEL_WORLD_H
#define VOXEL_WORLD_H

#include "Block.h"
#include "chunk/Chunk.h"
#include <vector>

class World
{
private:
    unsigned int chunkId;
    std::vector<Chunk*> chunksLoaded;
public:
    void init();
    void cleanup();
    void loop(float d, float d1, float d2);
    void loadChunksAroundRadius(float x, float y, float z, int i);
    bool chunkHasLoaded(int chunkX, int chunkY);
    void loadChunk(int chunkX, int chunkY);
    void unloadChunk(int chunkX, int chunkY);
    void cleanChunksOutOfRadius(int chunkX, int chunkY, int r);
};


#endif //VOXEL_WORLD_H
