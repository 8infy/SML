#pragma once

#include "utils.h"
#include "vec4.h"

namespace sml {

	class mat4
	{
	public:
		union
		{
			float elements[16];

			struct
			{
				vec4 columns[4];
			};
		};
	public:
		
		mat4()
		{
			memset(elements, 0, sizeof(float) * 16);
		}

		mat4(float diagonal)
		{
			memset(elements, 0, sizeof(float) * 16);

			columns[0][0] = diagonal;
			columns[1][1] = diagonal;
			columns[2][2] = diagonal;
			columns[3][3] = diagonal;
		}

		static mat4 identity()
		{
			return mat4(1.0f);
		}

		vec4& operator[](int column)
		{
			return columns[column];
		}

		const vec4& operator[](int column) const
		{
			return columns[column];
		}

		float* data()
		{
			return &elements[0];
		}

		void operator*=(const mat4& other)
		{
			mat4 result = *this;

			result[0] = columns[0] * other[0][0] + columns[1] * other[0][1] + columns[2] * other[0][2] + columns[3] * other[0][3];
			result[1] = columns[0] * other[1][0] + columns[1] * other[1][1] + columns[2] * other[1][2] + columns[3] * other[1][3];
			result[2] = columns[0] * other[2][0] + columns[1] * other[2][1] + columns[2] * other[2][2] + columns[3] * other[2][3];
			result[3] = columns[0] * other[3][0] + columns[1] * other[3][1] + columns[2] * other[3][2] + columns[3] * other[3][3];

			this->columns[0] = result.columns[0];
			this->columns[1] = result.columns[1];
			this->columns[2] = result.columns[2];
			this->columns[3] = result.columns[3];
		}

		void translate(const vec3& translation)
		{
			columns[3][0] += translation[0];
			columns[3][1] += translation[1];
			columns[3][2] += translation[2];
		}

		void scale(const vec3& scalars)
		{
			columns[0][0] *= scalars[0];
			columns[1][1] *= scalars[1];
			columns[2][2] *= scalars[2];
		}

		void rotate(float angle, const vec3& axis)
		{
			mat4 rotation(1.0f);

			float r = to_radians(angle);
			float c = cos(r);
			float s = sin(r);
			float omc = 1.0f - c;

			float x = axis.x;
			float y = axis.y;
			float z = axis.z;

			rotation[0][0] = x * x * omc + c;
			rotation[0][1] = x * y * omc + z * s;
			rotation[0][2] = x * z * omc - y * s;

			rotation[1][0] = x * y * omc - z * s;
			rotation[1][1] = y * y * omc + c;
			rotation[1][2] = y * z * omc + x * s;

			rotation[2][0] = x * z * omc + y * s;
			rotation[2][1] = y * z * omc - x * s;
			rotation[2][2] = z * z * omc + c;

			*this *= rotation;
		}

		//friends
		friend mat4 operator*(const mat4& lhs, const mat4& rhs)
		{
			mat4 result;

			result[0] = lhs[0] * rhs[0][0] + lhs[1] * rhs[0][1] + lhs[2] * rhs[0][2] + lhs[3] * rhs[0][3];
			result[1] = lhs[0] * rhs[1][0] + lhs[1] * rhs[1][1] + lhs[2] * rhs[1][2] + lhs[3] * rhs[1][3];
			result[2] = lhs[0] * rhs[2][0] + lhs[1] * rhs[2][1] + lhs[2] * rhs[2][2] + lhs[3] * rhs[2][3];
			result[3] = lhs[0] * rhs[3][0] + lhs[1] * rhs[3][1] + lhs[2] * rhs[3][2] + lhs[3] * rhs[3][3];
			
			return result;
		}
	};
}