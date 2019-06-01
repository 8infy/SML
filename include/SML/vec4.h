#pragma once

#include "vec2.h"
#include "vec3.h"

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

		float& operator[](int index)
		{
			return elements[index];
		}

		void operator+=(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
		}

		void operator+=(float scalar)
		{
			this->x += scalar;
			this->y += scalar;
			this->z += scalar;
			this->w += scalar;
		}

		void operator-=(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
		}

		void operator-=(float scalar)
		{
			this->x -= scalar;
			this->y -= scalar;
			this->z -= scalar;
			this->w -= scalar;
		}

		void operator*=(const vec4& other)
		{
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
			this->w *= other.w;
		}

		void operator*=(float scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			this->w *= scalar;
		}

		void operator/=(const vec4& other)
		{
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
			this->w /= other.w;
		}

		void operator/=(float scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			this->w /= scalar;
		}

		float dot(const vec4& other)
		{
			return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
		}

		float* data()
		{
			return &elements[0];
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

		friend vec4 operator+(vec4 lhs, float scalar)
		{
			lhs.x += scalar;
			lhs.y += scalar;
			lhs.z += scalar;
			lhs.w += scalar;

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

		friend vec4 operator-(vec4 lhs, float scalar)
		{
			lhs.x -= scalar;
			lhs.y -= scalar;
			lhs.z -= scalar;
			lhs.w -= scalar;

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

		friend vec4 operator*(vec4 lhs, float scalar)
		{
			lhs.x *= scalar;
			lhs.y *= scalar;
			lhs.z *= scalar;
			lhs.w *= scalar;

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

		friend vec4 operator/(vec4 lhs, float scalar)
		{
			lhs.x /= scalar;
			lhs.y /= scalar;
			lhs.z /= scalar;
			lhs.w /= scalar;

			return lhs;
		}
	};
}