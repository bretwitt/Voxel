#include <glad/glad.h>
#include "VBO.h"

void VBO::bufferFloat(float * data, int size) {
    glGenBuffers(1,&VBO_ID);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VBO::unbind() {
    glBindBuffer(0,0);
}