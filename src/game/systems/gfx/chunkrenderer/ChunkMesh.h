#ifndef VOXEL_CHUNKMESH_H
#define VOXEL_CHUNKMESH_H

#include <vector>
#include "../../gamelogic/world/Block.h"
#include "../../gamelogic/world/chunk/Chunk.h"

class ChunkMesh {
private:
    unsigned int indSize = 0;
    unsigned int block[CHUNK_X][CHUNK_Y][CHUNK_Z];
    unsigned int quadMask[CHUNK_X][CHUNK_Y][CHUNK_Z];
    unsigned int quadIndex;
    int chunkX, chunkY;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    void buildMesh();
    void clearMesh();


public:
    ChunkMesh();
    std::vector<float> getVertices();
    std::vector<unsigned int> getIndices();
    void updateChunkMesh(Chunk chunk);
    void printQuadSpan();
    void createQuad(int dir, float w, float l, float h, float x, float y, float z);
    int quadSpan(int x0, int y0, int z0);

    void calculateNormals();
};


#endif //VOXEL_CHUNKMESH_H
