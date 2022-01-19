//
// Created by legon on 5/20/2021.
//

#ifndef VOXEL_VBO_H
#define VOXEL_VBO_H

class VBO {

public:
    void bufferFloat(float verts[], int size);
    bool generated;
    unsigned int VBO_ID;
    void unbind();
};


#endif //VOXEL_VBO_H
