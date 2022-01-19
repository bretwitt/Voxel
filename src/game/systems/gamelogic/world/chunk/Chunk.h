#ifndef VOXEL_CHUNK_H
#define VOXEL_CHUNK_H

#include "../Block.h"
#include <srutil/delegate/delegate.hpp>
#include <noise/noise.h>

#define CHUNK_X 16
#define CHUNK_Y 50
#define CHUNK_Z 16

class Chunk {
public:
    Block *** blocks{};
    int chunkId;
    int worldX, worldY;
    int chunkX, chunkY;

    void generate();
    Chunk(int chunkId, int chunkX, int chunkY);
    Chunk();
    void init();
    void cleanup();
};
#endif //VOXEL_CHUNK_H
