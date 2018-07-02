/**
 * @file    signals.hpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */

#ifndef SIGNALS_SIGNAL_HPP_
#define SIGNALS_SIGNAL_HPP_

#include <functional>

namespace signals {

template <typename Ret, typename ...Args>
class CSignal {
public:
    using InvokedFunction = std::function<Ret(Args...)>;

public:
    explicit CSignal(InvokedFunction _callee);

public:
    Ret call(Args... _args);

protected:
    InvokedFunction m_invoked_function;
};

template <typename Ret, typename ...Args>
CSignal<Ret, Args...>::CSignal(InvokedFunction _callee)
    : m_invoked_function(_callee)
{}

template <typename Ret, typename ...Args>
Ret CSignal<Ret, Args...>::call(Args... _args) {
    return m_invoked_function(_args...);
}

template <typename Ret, typename Type, typename ...Args>
decltype(auto) make_signal(Type* _object, Ret(Type::*_invoked_method)(Args...)) {
    return CSignal<Ret, Args...>([=](Args... _args) {
        return (_object->*_invoked_method)(_args...);
    });
}

template <typename Ret, typename ...Args>
decltype(auto) make_signal(Ret(*_invoked_function)(Args...)) {
    return CSignal<Ret, Args...>(_invoked_function);
}

} // signals

#endif  // SIGNALS_SIGNAL_HPP_
