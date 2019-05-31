#pragma once

#include "defines.h"

namespace sml {

	inline float to_radians(float degrees)
	{
		return degrees * SML_PI_OVER_180;
	}

	inline float to_degrees(float radians)
	{
		return radians * SML_180_OVER_PI;
	}
}
