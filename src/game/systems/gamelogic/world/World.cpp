
#include <vector>
#include "World.h"
#include "events/WorldEventHandler.h"
#include "events/LoadChunkEvent.h"
#include "events/UnloadChunkEvent.h"

void World::init() {
}

void World::loop(float x, float y, float z) {
    loadChunksAroundRadius(x,y,z,5);
}

void World::loadChunksAroundRadius(float x, float y, float z, int rad) {
    int chunkX, chunkY;
    chunkX = floor(x / CHUNK_X);
    chunkY = floor(z / CHUNK_Z);
    for(int xi = -rad; xi < rad; xi++) {
        for(int yi = -rad; yi < rad; yi++) {
            if(pow(pow(abs(xi),2) + pow(abs(yi),2), 0.5) <= rad) {
                if(!chunkHasLoaded(xi + chunkX,yi + chunkY)) {
                    loadChunk(xi + chunkX, yi + chunkY);
                }
            }
        }
    }
    cleanChunksOutOfRadius(chunkX,chunkY,rad);
}

void World::loadChunk(int chunkX, int chunkY) {
    Chunk* chunk = new Chunk(++chunkId, chunkX, chunkY);
    chunk->generate();
    chunksLoaded.push_back(chunk);
    LoadChunkEvent * event = new LoadChunkEvent(chunk);
    WorldEventHandler::getInstance()->notify(event);
}

void World::cleanChunksOutOfRadius(int chunkX, int chunkY, int r) {
    int chunkXi = 0, chunkYi = 0;
    std::vector<Chunk*> toClean;
    for(int i = 0; i < chunksLoaded.size(); i++) {
        chunkXi = chunksLoaded[i]->chunkX;
        chunkYi = chunksLoaded[i]->chunkY;
        if(pow(pow(abs(chunkXi - chunkX),2) + pow(abs(chunkYi - chunkY),2), 0.5) > r) {
            toClean.push_back(chunksLoaded[i]);
        }
    }
    for(int j = 0; j < toClean.size(); j++) {
        Chunk * c = toClean[j];
        unloadChunk(c->chunkX, c->chunkY);
    }
}

void World::unloadChunk(int chunkX, int chunkY) {
    for(int i = 0; i < chunksLoaded.size(); i++) {
        if(chunkX == chunksLoaded[i]->chunkX && chunkY == chunksLoaded[i]->chunkY) {
            Chunk * c = chunksLoaded[i];
            WorldEventHandler::getInstance()->notify(new UnloadChunkEvent(c));
            chunksLoaded.erase(chunksLoaded.begin()+i);
            c->cleanup();
            delete(c);
        }
    }
}

bool World::chunkHasLoaded(int chunkX, int chunkY) {
    for(int i = 0; i < chunksLoaded.size(); i++) {
        if(chunksLoaded[i]->chunkX == chunkX && chunksLoaded[i]->chunkY == chunkY) {
            return true;
        }
    }
    return false;
}

void World::cleanup() {
    for(int i = 0; i < chunksLoaded.size(); i++) {
        chunksLoaded[i]->cleanup();
        delete(chunksLoaded[i]);
    }
}
