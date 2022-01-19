#ifndef VOXEL_EVENTHANDLER_H
#define VOXEL_EVENTHANDLER_H


#include "../gfx/GameRenderSystem.h"
#include "Observer.h"

class EventHandler {
private:
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer *observer);
    void notify(Event *event);
};


#endif //VOXEL_EVENTHANDLER_H
