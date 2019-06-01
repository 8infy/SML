#pragma once

namespace sml {

	class vec2
	{
	public:
		union {

			struct
			{
				float elements[2];
			};

			struct
			{
				float x, y;
			};

		};
	public:
		vec2() : x(0.0f), y(0.0f) {}

		vec2(float scalar) : x(scalar), y(scalar) {}

		vec2(float x, float y) : x(x), y(y) {}

		void operator+=(const vec2& other)
		{
			this->x += other.x;
			this->y += other.y;
		}

		void operator+=(float scalar)
		{
			this->x += scalar;
			this->y += scalar;
		}

		void operator-=(const vec2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
		}

		void operator-=(float scalar)
		{
			this->x -= scalar;
			this->y -= scalar;
		}

		void operator*=(const vec2& other)
		{
			this->x *= other.x;
			this->y *= other.y;
		}

		void operator*=(float scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
		}

		void operator/=(const vec2& other)
		{
			this->x /= other.x;
			this->y /= other.y;
		}

		void operator/=(float scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
		}

		float dot(const vec2& other)
		{
			return this->x * other.x + this->y * other.y;
		}

		//friends
		friend vec2 operator+(vec2 lhs, const vec2& rhs)
		{
			lhs.x += rhs.x;
			lhs.y += rhs.y;

			return lhs;
		}

		friend vec2 operator+(vec2 lhs, float scalar)
		{
			lhs.x += scalar;
			lhs.y += scalar;

			return lhs;
		}

		friend vec2 operator-(vec2 lhs, const vec2& rhs)
		{
			lhs.x -= rhs.x;
			lhs.y -= rhs.y;

			return lhs;
		}

		friend vec2 operator-(vec2 lhs, float scalar)
		{
			lhs.x -= scalar;
			lhs.y -= scalar;

			return lhs;
		}

		friend vec2 operator*(vec2 lhs, const vec2& rhs)
		{
			lhs.x *= rhs.x;
			lhs.y *= rhs.y;

			return lhs;
		}

		friend vec2 operator*(vec2 lhs, float scalar)
		{
			lhs.x *= scalar;
			lhs.y *= scalar;

			return lhs;
		}

		friend vec2 operator/(vec2 lhs, const vec2& rhs)
		{
			lhs.x /= rhs.x;
			lhs.y /= rhs.y;

			return lhs;
		}

		friend vec2 operator/(vec2 lhs, float scalar)
		{
			lhs.x /= scalar;
			lhs.y /= scalar;

			return lhs;
		}
	};
}