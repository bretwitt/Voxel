//
// Created by legon on 6/1/2021.
//

#include "WorldEventHandler.h"

WorldEventHandler * WorldEventHandler::INSTANCE = NULL;

WorldEventHandler * WorldEventHandler::getInstance() {
    if(INSTANCE == nullptr) {
        INSTANCE = new WorldEventHandler();
    }
    return INSTANCE;
}
