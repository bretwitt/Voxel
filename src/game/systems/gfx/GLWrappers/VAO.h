//
// Created by legon on 5/20/2021.
//

#ifndef VOXEL_VAO_H
#define VOXEL_VAO_H


class VAO {
private:
    unsigned int n = 0;
public:
    unsigned int VAO_ID;
    void createFloatVAP(unsigned int index, unsigned int size, unsigned int stride);
    void create();
    void bind();
    void unbind();
};


#endif //VOXEL_VAO_H
