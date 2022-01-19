#ifndef VOXEL_SHADER_H
#define VOXEL_SHADER_H


#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader {

public:
    unsigned int shaderProg;
    void use();
    void loadFromFile(char * vertexPath, char * fragPath);
    void setUniformMat4(const char *, glm::mat4);
    void setUniformVec3(const GLchar *name, glm::vec3 vec);

    void setUniformInt(const GLchar *name, int i);
};


#endif //VOXEL_SHADER_H
