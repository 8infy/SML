#pragma once

/*----Misc----*/
#include "defines.h"
#include "utils.h"
/*----Vectors----*/
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

/*----Functions----*/
namespace sml {

	inline float dot(const vec2& lhs, const vec2& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	inline float dot(const vec3& lhs, const vec3& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	inline float dot(const vec4& lhs, const vec4& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
	}
}
