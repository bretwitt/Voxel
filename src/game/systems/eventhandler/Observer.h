#ifndef VOXEL_OBSERVER_H
#define VOXEL_OBSERVER_H

#include "Event.h"

class Observer {
public:
    virtual void OnNotify(Event * event) = 0;
};


#endif //VOXEL_OBSERVER_H
