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
    Event() = default;
};

class Handler {
public:
    void handleEvent(Event _event) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main() {
    std::cout << "Library version: " << signals::version() << std::endl;

    Handler handler;
    signals::CSlot<void, Event> slot;
    slot.connect(signals::make_signal(handler, &Handler::handleEvent));
    slot.connect(signals::make_signal(handler, &Handler::handleEvent));
    slot.emit(Event());

    return 0;
}
