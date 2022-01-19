#include "EventHandler.h"

void EventHandler::registerObserver(Observer* observer) {
    observers.push_back(observer);
}

void EventHandler::notify(Event* event) {
    for(int i = 0; i < observers.size(); i++) {
        observers[i]->OnNotify(event);
    }
    delete(event);
}
