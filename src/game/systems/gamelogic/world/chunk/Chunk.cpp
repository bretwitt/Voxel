#include <cmath>
#include <iostream>
#include "Chunk.h"
#include "../../../../../vendor/SimplexNoise/SimplexNoise.h"
#include "../../../../../vendor/OpenSimplex/OpenSimplexNoise.h"

OpenSimplexNoise _noise;

Chunk::Chunk(int chunkId, int chunkX, int chunkY)
{
    this->worldX = worldX * chunkX;
    this->worldY = worldY * chunkX;
    this->chunkX = chunkX;
    this->chunkY = chunkY;
    this->chunkId = chunkId;
    init();
}

Chunk::Chunk() {
    chunkId = 0;
    worldX = 0;
    worldY = 0;
    chunkX = 0;
    chunkY = 0;
    init();
}

void Chunk::init() {
    blocks = new Block ** [CHUNK_X]();
    for (int x = 0; x < CHUNK_X; x++)
    {
        blocks[x] = new Block *[CHUNK_Y]();
        for (int y = 0; y < CHUNK_Y; y++)
            blocks[x][y] = new Block [CHUNK_Z]();
    }
    for(int x = 0; x < CHUNK_X; x++) {
        for(int y = 0 ; y < CHUNK_Y; y++) {
            for(int z = 0; z < CHUNK_Z; z++) {
                blocks[x][y][z] = Block();
                blocks[x][y][z].type = 0;
            }
        }
    }
}

void Chunk::generate() {
    for(int x = 0 ; x < CHUNK_X; x++) {
        for(int z = 0; z < CHUNK_Z; z++) {
            //double yMax = SimplexNoise::noise(x / chunkX - 0.5, z / chunkY - 0.5) * 1.5f + 10.0f;
            //double nx = x * (chunkX + 0.5) / 16; //((float)(x * chunkX)) / CHUNK_X
            //double ny = z * (chunkY + 0.5) / 16; //((float)(z * chunkY)) / CHUNK_Z
            double yMax = _noise.Evaluate(x,z) * 3 + 5.0f;
            for (int y = 0; y <= floor(yMax); y++) {
                blocks[x][y][z] = Block();
                blocks[x][y][z].type = 1;
            }
        }
    }
}

void Chunk::cleanup() {
    for (int x = 0; x < CHUNK_X; x++)
    {
        for (int y = 0; y < CHUNK_Y; y++)
            delete[] blocks[x][y];
        delete[] blocks[x];
    }
    delete[] blocks;
}