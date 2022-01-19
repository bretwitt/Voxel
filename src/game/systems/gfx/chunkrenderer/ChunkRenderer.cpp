#include <glad/glad.h>
#include <glm/ext/matrix_transform.hpp>
#include "ChunkRenderer.h"
#include "../camera/Camera.h"

void ChunkRenderer::init() {
    sizeInd = 0;
    vao = VAO();
    vao.create();

    vbo = VBO();
    ebo = EBO();

    texture.init((char*)"C:\\Users\\legon\\CLionProjects\\Voxel\\src\\game\\systems\\gfx\\chunkrenderer\\wall.jpg");

    chunkMesh = ChunkMesh();
    updateChunk(chunkMesh);
}

void ChunkRenderer::setShader(Shader shader) {
    this->shader = shader;
}

void ChunkRenderer::initializeBuiltInShader() {
    shader = Shader();
    shader.loadFromFile("C:\\Users\\legon\\CLionProjects\\Voxel\\src\\game\\systems\\gfx\\shaders\\BasicVertexShader.GLSL", "C:\\Users\\legon\\CLionProjects\\Voxel\\src\\game\\systems\\gfx\\shaders\\BasicFragShader.GLSL");
    shader.use();
}

void ChunkRenderer::preloop() {

}

void ChunkRenderer::loop() {
    drawChunk();
}

void ChunkRenderer::drawChunk() {
    shader.use();
    texture.use();

    Camera::getInstance()->getMatrices(view,projection);
    model = glm::mat4(1.0f);
    shader.setUniformMat4("projection", projection);
    shader.setUniformMat4("view", view);
    shader.setUniformMat4("model", model);
    shader.setUniformVec3("lightPos", glm::vec3(25,30,24));
    vao.bind();
    glDrawElements(GL_TRIANGLES,sizeInd,GL_UNSIGNED_INT, 0);
    vao.unbind();
}

void ChunkRenderer::postloop() {

}

void ChunkRenderer::updateChunk(Chunk chunk) {
    chunkId = chunk.chunkId;
    chunkMesh.updateChunkMesh(chunk);
    updateChunk(chunkMesh);
}

void ChunkRenderer::updateChunk(ChunkMesh mesh) {
    std::vector<float> verts = mesh.getVertices();
    std::vector<unsigned int> indices = mesh.getIndices();
    updateChunk(&verts[0], verts.size(), &indices[0], indices.size());
}

void ChunkRenderer::updateChunk(float * verts, unsigned int size, unsigned int * indices, unsigned int sizeind) {
    texture.use();
    vao.create();
    vao.bind();
    vbo.bufferFloat(verts,size * sizeof(float));
    ebo.bufferIndices(indices, sizeind * sizeof(unsigned int));
    vao.createFloatVAP(0, 3, 8);
    vao.createFloatVAP(1,3,8);
    vao.createFloatVAP(2,2,8);
    vao.unbind();
    sizeInd = sizeind;
}

void ChunkRenderer::cleanup() {
    // Clean up buffers here
}