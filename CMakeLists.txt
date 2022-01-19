cmake_minimum_required(VERSION 3.16.3)
project(Voxel)


set(CMAKE_CXX_STANDARD 14)

find_package(boost CONFIG)
find_package(imgui CONFIG)

add_library(glad "C:/MinGW/include/glad/glad.h" "glad.c" )
target_include_directories(glad PUBLIC C:/MinGW/include)

add_executable(Voxel glad.c main.cpp src/game/systems/input/InputHandler.cpp src/game/systems/input/InputHandler.h src/game/systems/gamelogic/player/PlayerController.cpp src/game/systems/gamelogic/player/PlayerController.h src/game/systems/gfx/camera/Camera.cpp src/game/systems/gfx/camera/Camera.h src/game/systems/gfx/GLWrappers/VAO.cpp src/game/systems/gfx/GLWrappers/VBO.cpp src/game/systems/gfx/windows/Window.cpp src/game/systems/gfx/ui/UI.cpp src/game/systems/gfx/ui/UI.cpp
        src/vendor/imgui/imgui.cpp src/vendor/imgui/imgui_draw.cpp src/vendor/imgui/imgui_tables.cpp src/game/VoxelGame.cpp src/game/VoxelGame.h src/game/systems/System.h src/game/systems/gamelogic/GameLogicSystem.cpp src/game/systems/gamelogic/GameLogicSystem.h src/game/systems/gfx/GameRenderSystem.cpp src/game/systems/gfx/GameRenderSystem.h
        src/vendor/imgui/imgui_widgets.cpp src/vendor/imgui/imgui_impl_glfw.cpp src/vendor/imgui/imgui_impl_opengl3.cpp src/game/systems/gfx/shaders/Shader.cpp src/game/systems/gfx/shaders/Shader.h src/game/systems/gamelogic/world/Block.h src/game/systems/gfx/GLWrappers/EBO.cpp src/game/systems/gfx/GLWrappers/EBO.h src/game/systems/gfx/chunkrenderer/ChunkRenderer.cpp src/game/systems/gfx/chunkrenderer/ChunkRenderer.h src/game/systems/gfx/chunkrenderer/ChunkMesh.cpp src/game/systems/gfx/chunkrenderer/ChunkMesh.h src/game/systems/gfx/worldrenderer/WorldRenderer.h src/game/systems/gamelogic/world/chunk/Chunk.cpp src/game/systems/gamelogic/world/chunk/Chunk.h src/game/systems/gfx/worldrenderer/WorldRenderer.cpp
        src/game/systems/gamelogic/world/World.cpp src/vendor/SimplexNoise/SimplexNoise.cpp src/game/systems/gfx/textures/Texture.cpp src/game/systems/gfx/textures/Texture.h src/game/systems/eventhandler/EventHandler.cpp src/game/systems/eventhandler/EventHandler.h src/game/systems/eventhandler/Observer.cpp src/game/systems/eventhandler/Observer.h src/game/systems/eventhandler/Event.cpp src/game/systems/eventhandler/Event.h src/game/systems/gamelogic/world/events/LoadChunkEvent.cpp src/game/systems/gamelogic/world/events/LoadChunkEvent.h src/game/systems/gamelogic/world/events/WorldEventHandler.cpp src/game/systems/gamelogic/world/events/WorldEventHandler.h src/game/systems/gamelogic/world/events/UnloadChunkEvent.cpp src/game/systems/gamelogic/world/events/UnloadChunkEvent.h src/vendor/OpenSimplex/OpenSimplexNoise.h)

target_link_libraries(Voxel ${CMAKE_DL_LIBS} mingw32 imm32 glad glfw3dll)

