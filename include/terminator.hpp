/**
 * @file    terminator.hpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */

#ifndef SIGNALS_TERMINATOR_HPP_
#define SIGNALS_TERMINATOR_HPP_

template <typename Ret, typename ...Args>
class terminator {
public:
    Ret wrap_call(Args... _args) {
        return Ret();
    }
};

#endif  // SIGNALS_TERMINATOR_HPP_
