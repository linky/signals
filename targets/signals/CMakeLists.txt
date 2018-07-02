cmake_minimum_required(VERSION 3.0)

set(SIGNALS_INC
        ../../include/slot.hpp
        ../../include/signal.hpp
        ../../include/terminator.hpp)

set(SIGNALS_SRC
        ../../src/signals.cpp)

add_library(signals ${SIGNALS_SRC} ${SIGNALS_INC})
