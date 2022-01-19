
#ifndef VOXEL_PLAYERCONTROLLER_H
#define VOXEL_PLAYERCONTROLLER_H
#include <iostream>
#include "PlayerController.h"

class PlayerController {

public:
    float x,y,z;
    void loop();
    void init();
    void handleTranslation();
    void handleRotation();
    double sensitivity = 0.1;
};


#endif //VOXEL_PLAYERCONTROLLER_H
