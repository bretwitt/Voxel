#ifndef VOXEL_CHUNKRENDERER_H
#define VOXEL_CHUNKRENDERER_H


#include "../GLWrappers/VBO.h"
#include "../GLWrappers/VAO.h"
#include "../shaders/Shader.h"
#include "../GLWrappers/EBO.h"
#include "ChunkMesh.h"
#include "../textures/Texture.h"

class ChunkMesh;

class ChunkRenderer {
private:
    VBO vbo;
    VAO vao;
    Shader shader;
    EBO ebo;
    Texture texture;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 model;
    unsigned int sizeInd;
    ChunkMesh chunkMesh;
    void updateChunk(ChunkMesh mesh);

public:
    int chunkId;
    void init();
    void preloop();
    void loop();
    void drawChunk();
    void postloop();
    void updateChunk(Chunk chunk);

    void cleanup();

    void updateChunk(float *verts, unsigned int size, unsigned int *indices, unsigned int sizeind);

    void initializeBuiltInShader();

    void setShader(Shader shader);
};

#endif //VOXEL_CHUNKRENDERER_H
