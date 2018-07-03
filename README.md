<h1>Signals</h1>
Basic implementation of the <i>signals/slots</i> mechanism

<h2>Usage example</h2>

```cpp

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
```