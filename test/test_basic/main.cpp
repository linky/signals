/**
 * @file    main.cpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */
 
#include <iostream>

#include "signals.h"

class Event {
public:
    Event() {
        std::cout << "Event created\n";
    }
};

class Handler {
public:
    void handleEvent(Event _event) {}
};

int main() {
    std::cout << "Library version: " << signals::version() << std::endl;

    Handler handler;
    signals::CSlot<void, Event> slot;
    slot.connect(signals::make_signal(&handler, &Handler::handleEvent));
    slot.emit(Event());

    return 0;
}