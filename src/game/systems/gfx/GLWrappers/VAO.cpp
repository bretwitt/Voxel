#include <glad/glad.h>
#include <iostream>
#include "VAO.h"


void VAO::create() {
    glGenVertexArrays(1, &VAO_ID);
    n = 0;
}

void VAO::createFloatVAP(unsigned int index, unsigned int size, unsigned int stride) {
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(n * sizeof(float)));
    glEnableVertexAttribArray(index);
    n += size;
}

void VAO::bind()
{
    glBindVertexArray(VAO_ID);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}