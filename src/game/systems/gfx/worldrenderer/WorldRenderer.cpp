#include <iostream>
#include "WorldRenderer.h"
#include "../../input/InputHandler.h"
#include "../../gamelogic/world/events/LoadChunkEvent.h"
#include "../../gamelogic/world/events/WorldEventHandler.h"
#include "../../gamelogic/world/events/UnloadChunkEvent.h"

bool renderWireframe = false;
Shader worldShader;

void WorldRenderer::init() {
    WorldEventHandler::getInstance()->registerObserver(this);
    chunkRenderer = std::vector<ChunkRenderer * >();
    worldShader.loadFromFile("C:\\Users\\legon\\CLionProjects\\Voxel\\src\\game\\systems\\gfx\\shaders\\BasicVertexShader.GLSL", "C:\\Users\\legon\\CLionProjects\\Voxel\\src\\game\\systems\\gfx\\shaders\\BasicFragShader.GLSL");
    worldShader.use();
}

void WorldRenderer::loop() {
    if(InputHandler::getInstance()->getKeyUp(GLFW_KEY_Z))
    {
        if(!renderWireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            renderWireframe = true;
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            renderWireframe = false;
        }
    }
}

void WorldRenderer::renderWorld() {
    for (int i = 0; i < chunkRenderer.size(); i++) {
        chunkRenderer[i]->drawChunk();
    }
}

void WorldRenderer::OnNotify(Event* event) {
    if(event->name == "LoadChunk") {
        LoadChunkEvent lcEvent = *((LoadChunkEvent*)event);
        loadChunk(*(lcEvent.chunk));
    }
    if(event->name == "UnloadChunk") {
        UnloadChunkEvent ulcEvent = *((UnloadChunkEvent*)event);
        unloadChunk(*(ulcEvent.chunk));
    }
}

void WorldRenderer::loadChunk(Chunk chunk) {
    ChunkRenderer* renderer = new ChunkRenderer();
    renderer->setShader(worldShader);
    renderer->init();
    renderer->updateChunk(chunk);
    chunkRenderer.push_back(renderer);
}

void WorldRenderer::updateChunk(Chunk chunk) {
    for(int i = 0; i < chunkRenderer.size(); i++) {
        if(chunkRenderer[i]->chunkId == chunk.chunkId) {
            chunkRenderer[i]->updateChunk(chunk);
        }
    }
}

void WorldRenderer::unloadChunk(unsigned int chunkID) {
    for(int i = 0; i < chunkRenderer.size(); i++) {
        if(chunkRenderer[i]->chunkId == chunkID) {
            ChunkRenderer * renderer = chunkRenderer[i];
            chunkRenderer.erase(chunkRenderer.begin() + i);
            unloadChunk(renderer);
        }
    }
}

void WorldRenderer::unloadChunk(ChunkRenderer * renderer) {
    renderer->cleanup();
    delete(renderer);
}

void WorldRenderer::unloadChunk(Chunk chunk) {
    unloadChunk(chunk.chunkId);
}

void WorldRenderer::unloadWorld() {
    for(int i = 0; i < chunkRenderer.size(); i++) {
        unloadChunk(chunkRenderer[i]);
        delete(chunkRenderer[i]);
    }
}

void WorldRenderer::cleanup() {
    unloadWorld();
}
