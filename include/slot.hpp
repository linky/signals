/**
 * @file    slot.hpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */

#ifndef SIGNALS_SLOT_HPP_
#define SIGNALS_SLOT_HPP_

#include "signal.hpp"
#include "terminator.hpp"

namespace signals {

template <typename Ret, typename ...Args>
class CSlot {
protected:
    using ConnectedSignal = CSignal<Ret, Args...>;
    using Terminator = terminator<Ret, Args...>;

public:
    CSlot();

public:
    void connect(ConnectedSignal _signal);

    Ret emit(Args... _args);

protected:
    Terminator      m_terminator;
    ConnectedSignal m_connected_signal;
};

template <typename Ret, typename ...Args>
CSlot<Ret, Args...>::CSlot()
    : m_terminator()
    , m_connected_signal(make_signal(&m_terminator, &terminator<Ret, Args...>::wrap_call))
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
