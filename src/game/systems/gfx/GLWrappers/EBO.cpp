
#include <glad/glad.h>
#include "EBO.h"

void EBO::bufferIndices(unsigned int * indices, int size) {
    glGenBuffers(1, &ebo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
