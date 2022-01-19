#define GLFW_DLL

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "src/game/VoxelGame.h"

int main() {
    VoxelGame game;
    game.init();
    return 0;
}
