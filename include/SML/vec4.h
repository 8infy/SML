#pragma once

#include "vec2"
#include "vec3"

namespace sml {

	class vec4
	{
	public:
		union {

			struct
			{
				float elements[4];
			};

			struct
			{
				float x, y, z, w;
			};

			struct
			{
				float r, g, b, a;
			};

		};
	public:
		vec4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

		vec4(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

		vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

		vec4(const vec2& vec2) : x(vec2.x), y(vec2.y), z(0.0f), w(1.0f) {}

		vec4(const vec2& vec2, float z) : x(vec2.x), y(vec2.y), z(z), w(1.0f) {}

		vec4(const vec2& vec2, float z, float w) : x(vec2.x), y(vec2.y), z(z), w(w) {}

		vec4(const vec3& vec3) : x(vec3.x), y(vec3.y), z(vec3.z), w(1.0f) {}

		vec4(const vec3& vec3, float w) : x(vec3.x), y(vec3.y), z(vec3.z), w(w) {}

		void operator+=(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
		}

		void operator-=(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
		}

		void operator*=(const vec4& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
		}

		void operator/=(const vec4& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
		}

		//friends
		friend vec4 operator+(vec4 lhs, const vec4& rhs)
		{
			lhs.x += rhs.x;
			lhs.y += rhs.y;
			lhs.z += rhs.z;
			lhs.w += rhs.w;

			return lhs;
		}

		friend vec4 operator-(vec4 lhs, const vec4& rhs)
		{
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;
			lhs.z -= rhs.z;
			lhs.w -= rhs.w;

			return lhs;
		}

		friend vec4 operator*(vec4 lhs, const vec4& rhs)
		{
			lhs.x *= rhs.x;
			lhs.y *= rhs.y;
			lhs.z *= rhs.z;
			lhs.w *= rhs.w;

			return lhs;
		}

		friend vec4 operator/(vec4 lhs, const vec4& rhs)
		{
			lhs.x /= rhs.x;
			lhs.y /= rhs.y;
			lhs.z /= rhs.z;
			lhs.w /= rhs.w;

			return lhs;
		}
	};
}