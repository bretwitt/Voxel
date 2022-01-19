#ifndef VOXEL_SYSTEM_H
#define VOXEL_SYSTEM_H

 class System {
    virtual void init() = 0;
    virtual void preloop() = 0;
    virtual void loop() = 0;
    virtual void postloop() = 0;
    virtual void cleanup() = 0;
};


#endif //VOXEL_SYSTEM_H
