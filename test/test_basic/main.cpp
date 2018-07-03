/**
 * @file    main.cpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */
 
#include <iostream>

#include "signals.h"

class Event {};

class Handler {
public:
    void handleEvent(const Event& /*_event*/) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main() {
    Handler handler;

    signals::CSlot<void, const Event&> slot;
    slot.connect(signals::make_signal(&handler, &Handler::handleEvent));
    slot.connect(signals::make_signal(&handler, &Handler::handleEvent));
    slot.emit(Event());

    return 0;
}