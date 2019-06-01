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

	inline vec3 cross(const vec3& lhs, const vec3& rhs)
	{
		return vec3(lhs.y * rhs.z - lhs.z * rhs.y,
                            lhs.z * rhs.x - lhs.x * rhs.z,
                            lhs.x * rhs.y - lhs.y * rhs.x);
	}

	inline float magnitude(const vec2& vec2)
	{
		return sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
	}

	inline float magnitude(const vec3& vec3)
	{
		return sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z);
	}

	inline vec2 normalize(const vec2& vec)
	{
		float len = magnitude(vec);

		return vec2(vec.x / len, vec.y / len);
	}

	inline vec3 normalize(const vec3& vec)
	{
		float len = magnitude(vec);

		return vec3(vec.x / len, vec.y / len, vec.z / len);
	}
}