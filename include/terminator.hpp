/**
 * @file    terminator.h
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */

#ifndef SIGNALS_TERMINATOR_H_
#define SIGNALS_TERMINATOR_H_

template <typename Ret, typename ...Args>
class terminator {
public:
    Ret wrap_call(Args... _args) {
        return Ret();
    }
};

#endif  // SIGNALS_TERMINATOR_H_
