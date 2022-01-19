#include <algorithm>
#include <iostream>
#include "ChunkMesh.h"


ChunkMesh::ChunkMesh() {
    chunkX = 0;
    chunkY = 0;

    for(int x = 0; x < CHUNK_X; x++) {
        for(int y = 0; y < CHUNK_Y; y++) {
            for(int z = 0; z < CHUNK_Z; z++) {
                block[x][y][z] = 0;
            }
        }
    }
    clearMesh();
}

void ChunkMesh::clearMesh() {
    indSize = 0;
    vertices = std::vector<float>(0);
    indices = std::vector<unsigned int>(0);
    for(int x = 0; x < CHUNK_X; x++) {
        for(int y = 0; y < CHUNK_Y; y++) {
            for(int z = 0; z < CHUNK_Z; z++) {
                quadMask[x][y][z] = 0;
            }
        }
    }
}

void ChunkMesh::updateChunkMesh(Chunk chunk) {
    for(int x = 0; x < CHUNK_X; x++) {
        for(int y = 0; y < CHUNK_Y; y++) {
            for(int z = 0; z < CHUNK_Z; z++) {
                if(chunk.blocks[x][y][z].type != 0){
                    block[x][y][z] = 1;
                }
            }
        }
    }
    chunkX = chunk.chunkX;
    chunkY = chunk.chunkY;
    buildMesh();
}

void ChunkMesh::buildMesh() {
    clearMesh();
    quadIndex = 1;

    for(int y = 0; y < CHUNK_Y; y++) {
        for(int x = 0; x < CHUNK_X; x++) {
            for(int z = 0; z < CHUNK_Z; z++) {
                if(block[x][y][z] != 0 && quadMask[x][y][z] == 0) {
                    quadIndex++;
                    unsigned int xSpan = quadSpan(x, y, z);
                    unsigned int zSpan = 0;
                    unsigned int xSpanI = 0;
                    for(int zi = z; zi < CHUNK_Z; zi++) {
                        xSpanI = quadSpan(x,y,zi);
                        if(xSpanI == xSpan) {
                            zSpan++;
                        } else {
                            break;
                        }
                    }

                    for(int i = 0; i < zSpan; i++) {
                        for(int j = 0; j < xSpan; j++) {
                            quadMask[x + j][y][z + i] = quadIndex;
                        }
                    }
                    createQuad(0, xSpan, zSpan, 1, x, y, z);
                    createQuad(1, xSpan, zSpan, 1, x, y, z);
                    createQuad(2, xSpan, zSpan, 1, x, y, z);
                    createQuad(3, xSpan, zSpan, 1, x, y, z);
                    createQuad(4, xSpan, zSpan, 1, x, y, z);
                    createQuad(5, xSpan, zSpan, 1, x, y, z);
                }
            }
        }
    }
}

int ChunkMesh::quadSpan(int x0, int y0, int z0) {
    unsigned int span = 0;
    for(int x = x0; x < CHUNK_X; x++){
        if(block[x][y0][z0] == 1 && quadMask[x][y0][z0] == 0) {
            span++;
        } else {
            break;
        }
    }
    return span;
}

void ChunkMesh::printQuadSpan() {
    std::cout << " + START CHUNK +" << std::endl;
    for(int y = 0; y < 16; y++) {
        for(int x = 0; x < 16; x++) {
            std::cout << quadMask[x][y];
        }
        std::cout << std::endl;
    }
    std::cout << "+ END CHUNK +" << std::endl;
}

void ChunkMesh::createQuad(int dir, float w, float l, float h,  float x, float y, float z) {
    x += chunkX * CHUNK_X;
    z += chunkY * CHUNK_Z;
    float verts[32] {
            x,y+h,z,   0.0f, 0.0f, 0.0f, 0.0f, 1.0f,  //0-2    3-5    6-7       (0)
            x+w,y+h,z, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  //8-10   11-13  14-15     (1)
            x,y,z,     0.0f, 0.0f, 0.0f, 0.0f, 0.0f,  //16-18  19-21  22-23     (2)
            x+w,y,z,   0.0f, 0.0f, 0.0f, 1.0f, 0.0f,  //24-26  27-29  30-31     (3)
    };

    unsigned int ind[6] {
            0 + indSize,1 + indSize,3 + indSize,
            3 + indSize,2 + indSize,0 + indSize
    };

    // Calculating verts and normals
    float normX, normY, normZ;

    switch(dir) {
        case 0:             // Front
            normX = 0;
            normY = 0;
            normZ = -1;
            verts[6] = 0.0f;
            verts[7] = h;
            verts[14] = w;
            verts[15] = h;
            verts[22] = 0;
            verts[23] = 0;
            verts[30] = w;
            verts[31] = 0;
            break;
        case 1:             // Back
            normX = 0;
            normY = 0;
            normZ = 1;
            verts[2] += l;
            verts[10] += l;
            verts[18] += l;
            verts[26] += l;
            verts[6] = 0.0f;
            verts[7] = h;
            verts[14] = w;
            verts[15] = h;
            verts[22] = 0;
            verts[23] = 0;
            verts[30] = w;
            verts[31] = 0;
            break;
        case 2:             // Right
            normX = 1;
            normY = 0;
            normZ = 0;
            verts[0] += w;
            verts[16] += w;
            verts[10] += l;
            verts[26] += l;

            verts[6] = 0.0f;
            verts[7] = h;
            verts[14] = l;
            verts[15] = h;
            verts[22] = 0;
            verts[23] = 0;
            verts[30] = l;
            verts[31] = 0;
            break;
        case 3:             // Left
            normX = -1;
            normY = 0;
            normZ = 0;
            verts[2] += l;
            verts[18] += l;
            verts[8] -= w;
            verts[24] -= w;

            verts[6] = 0.0f;
            verts[7] = h;
            verts[14] = l;
            verts[15] = h;
            verts[22] = 0;
            verts[23] = 0;
            verts[30] = l;
            verts[31] = 0;
            break;
        case 4:             // Top
            normX = 0;
            normY = 1;
            normZ = 0;
            verts[17] += h;
            verts[25] += h;
            verts[2] += l;
            verts[10] += l;

            verts[6] = 0.0f;
            verts[7] = l;
            verts[14] = w;
            verts[15] = l;
            verts[22] = 0;
            verts[23] = 0;
            verts[30] = w;
            verts[31] = 0;
            break;
        case 5:             // Bottom
            normX = 0;
            normY = -1;
            normZ = 0;
            verts[2] += l;
            verts[10] += l;
            verts[1] -= h;
            verts[9] -= h;

            verts[6] = 0.0f;
            verts[7] = h;
            verts[14] = l;
            verts[15] = h;
            verts[22] = 0;
            verts[23] = 0;
            verts[30] = l;
            verts[31] = 0;
            break;
    }

    verts[3] = normX;
    verts[4] = normY;
    verts[5] = normZ;
    verts[11] = normX;
    verts[12] = normY;
    verts[13] = normZ;
    verts[19] = normX;
    verts[20] = normY;
    verts[21] = normZ;
    verts[27] = normX;
    verts[28] = normY;
    verts[29] = normZ;

    indSize += 4;
    indices.insert(indices.end(), std::begin(ind), std::end(ind));
    vertices.insert(vertices.end(), std::begin(verts), std::end(verts));
}

void ChunkMesh::calculateNormals() {

}

std::vector<unsigned int> ChunkMesh::getIndices() {
    return indices;
}

std::vector<float> ChunkMesh::getVertices() {
    return vertices;
}
