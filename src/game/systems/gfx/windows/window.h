#ifndef VOXEL_WINDOW_H
#define VOXEL_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../chunkrenderer/ChunkRenderer.h"
#include "../worldrenderer/WorldRenderer.h"
#include "../../System.h"

class Window : System {
public:
    GLFWwindow * window_handle{};
    bool focus = false;
    void init() override;
    void loop() override;
    void preloop() override;
    void postloop() override;
    void close();
    void cleanup() override;
};


#endif //VOXEL_WINDOW_H
