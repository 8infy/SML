#pragma once

#include "defines.h"

namespace sml {

	inline float to_radians(const float& degrees)
	{
		return degrees * SML_PI_OVER_180;
	}

	inline float to_degrees(const float& radians)
	{
		return radians * SML_180_OVER_PI;
	}
}
