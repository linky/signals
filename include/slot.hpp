/**
 * @file    slot.hpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */

#ifndef SIGNALS_SLOT_HPP_
#define SIGNALS_SLOT_HPP_

#include <vector>

#include "signal.hpp"

namespace signals {

template <typename Ret, typename ...Args>
class CSlot {
public:
    using Signal = CSignal<Ret, Args...>;

protected:
    using Signals = std::vector<Signal>;

public:
    CSlot();

public:
    void connect(Signal _signal);
    void emit(Args... _args);

protected:
    Signals m_connected_signals;
};

template <typename Ret, typename ...Args>
CSlot<Ret, Args...>::CSlot()
    : m_connected_signals()
{}

template <typename Ret, typename ...Args>
void CSlot<Ret, Args...>::connect(Signal _signal) {
    m_connected_signals.push_back(_signal);
}

template <typename Ret, typename ...Args>
void CSlot<Ret, Args...>::emit(Args... _args) {
    for (typename Signals::size_type i = 0; i < m_connected_signals.size(); ++i)
        m_connected_signals[i].call(_args...);
}

} // signals

#endif  // SIGNALS_SLOT_HPP_
