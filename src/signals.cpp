/**
 * @file    signals.cpp
 * @author  isnullxbh
 * @date    02/07/18
 * @version 0.0.1
 */
 
#include "signals.h"

const char* g_version = "0.0.1";

namespace signals {

const char* version() {
    return g_version;
}

} // signals