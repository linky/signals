/**
 * @file    slot.hpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */

#ifndef SIGNALS_SLOT_HPP_
#define SIGNALS_SLOT_HPP_

#include "signal.hpp"

namespace signals {

template <typename Ret, typename ...Args>
class CSlot {
protected:
    using ConnectedSignal = CSignal<Ret, Args...>;

public:
    CSlot();

public:
    void connect(ConnectedSignal _signal);

    Ret emit(Args... _args);

protected:
    ConnectedSignal m_connected_signal;
};

template <typename Ret, typename ...Args>
CSlot<Ret, Args...>::CSlot()
    : m_connected_signal(nullptr)
{}

template <typename Ret, typename ...Args>
Ret CSlot<Ret, Args...>::emit(Args... _args) {
    return m_connected_signal.call(_args...);
}

template <typename Ret, typename ...Args>
void CSlot<Ret, Args...>::connect(ConnectedSignal _signal) {
    m_connected_signal = _signal;
}

}

#endif  // SIGNALS_SLOT_HPP_
