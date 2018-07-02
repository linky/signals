cmake_minimum_required(VERSION 3.0)

set(SIGNALS_INC
        ../../include/signals.h
        ../../include/slot.hpp
        ../../include/signal.hpp)

set(SIGNALS_SRC
        ../../src/signals.cpp)

add_library(signals ${SIGNALS_SRC} ${SIGNALS_INC})
