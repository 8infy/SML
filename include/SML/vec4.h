#pragma once

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

		vec4(const float& x, const float& y, const float& z, const float& w) : x(x), y(y), z(z), w(w) {}

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