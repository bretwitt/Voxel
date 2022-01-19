#ifndef VOXEL_TEXTURE_H
#define VOXEL_TEXTURE_H

#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>

class Texture {
private:
    unsigned int texture;
public:
    void init(char *texture_path);
    void use();
};


#endif //VOXEL_TEXTURE_H
