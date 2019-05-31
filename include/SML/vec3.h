#pragma once

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

		vec3(const float& x, const float& y, const float& z) : x(x), y(y), z(z) {}

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