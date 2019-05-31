#pragma once

#include "vec2.h"

namespace sml {

	class vec3
	{
	public:
		union {

			struct
			{
				float elements[3];
			};

			struct
			{
				float x, y, z;
			};

			struct
			{
				float r, g, b;
			};

		};
	public:
		vec3() : x(0.0f), y(0.0f), z(0.0f) {}

		vec3(float scalar) : x(scalar), y(scalar), z(scalar) {}

		vec3(float x, float y, float z) : x(x), y(y), z(z) {}

		vec3(const vec2& vec2) : x(vec2.x), y(vec2.y), z(0.0f) {}

		vec3(const vec2& vec2, float z) : x(vec2.x), y(vec2.y), z(z) {}

		void operator+=(const vec3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		void operator-=(const vec3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}

		void operator*=(const vec3& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
		}

		void operator/=(const vec3& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
		}

		//friends
		friend vec3 operator+(vec3 lhs, const vec3& rhs)
		{
			lhs.x += rhs.x;
			lhs.y += rhs.y;
			lhs.z += rhs.z;

			return lhs;
		}

		friend vec3 operator-(vec3 lhs, const vec3& rhs)
		{
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;
			lhs.z -= rhs.z;

			return lhs;
		}

		friend vec3 operator*(vec3 lhs, const vec3& rhs)
		{
			lhs.x *= rhs.x;
			lhs.y *= rhs.y;
			lhs.z *= rhs.z;

			return lhs;
		}

		friend vec3 operator/(vec3 lhs, const vec3& rhs)
		{
			lhs.x /= rhs.x;
			lhs.y /= rhs.y;
			lhs.z /= rhs.z;

			return lhs;
		}
	};
}