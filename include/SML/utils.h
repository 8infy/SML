#pragma once

#include "defines.h"

namespace sml {

    template<typename T>
    inline T to_radians(T degrees)
    {
        return static_cast<T>(degrees * SML_PI_OVER_180);
    }
    
    template<typename T>
    inline T to_degrees(T radians)
    {
        return static_cast<T>(radians * SML_180_OVER_PI);
    }
}
