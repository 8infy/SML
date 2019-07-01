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

		static mat4 orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			mat4 result(1.0f);

			result[0][0] = 2.0f / (right - left);
			result[1][1] = 2.0f / (top - bottom);
			result[2][2] = -2.0f / (far - near);

			result[3][0] = -(right + left) / (right - left);
			result[3][1] = -(top + bottom) / (top - bottom);
			result[3][2] = -(far + near) / (far - near);

			return result;
		}

		static mat4 perspective(float fov, float aspectRatio, float near, float far)
		{
			mat4 result(0.0f);

			float tanHalfFov = tan(to_radians(fov * 0.5f));

			result[0][0] = 1.0f / (aspectRatio * tanHalfFov);
			result[1][1] = 1.0f / tanHalfFov;
			result[2][2] = -(far + near) / (far - near);

			result[2][3] = -1.0f;

			result[3][2] = -(2.0f * far * near) / (far - near);

			return result;
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

		void invert()
		{
			float tempo[16];

			tempo[0] = elements[5] * elements[10] * elements[15] -
				elements[5] * elements[11] * elements[14] -
				elements[9] * elements[6] * elements[15] +
				elements[9] * elements[7] * elements[14] +
				elements[13] * elements[6] * elements[11] -
				elements[13] * elements[7] * elements[10];

			tempo[4] = -elements[4] * elements[10] * elements[15] +
				elements[4] * elements[11] * elements[14] +
				elements[8] * elements[6] * elements[15] -
				elements[8] * elements[7] * elements[14] -
				elements[12] * elements[6] * elements[11] +
				elements[12] * elements[7] * elements[10];

			tempo[8] = elements[4] * elements[9] * elements[15] -
				elements[4] * elements[11] * elements[13] -
				elements[8] * elements[5] * elements[15] +
				elements[8] * elements[7] * elements[13] +
				elements[12] * elements[5] * elements[11] -
				elements[12] * elements[7] * elements[9];

			tempo[12] = -elements[4] * elements[9] * elements[14] +
				elements[4] * elements[10] * elements[13] +
				elements[8] * elements[5] * elements[14] -
				elements[8] * elements[6] * elements[13] -
				elements[12] * elements[5] * elements[10] +
				elements[12] * elements[6] * elements[9];

			tempo[1] = -elements[1] * elements[10] * elements[15] +
				elements[1] * elements[11] * elements[14] +
				elements[9] * elements[2] * elements[15] -
				elements[9] * elements[3] * elements[14] -
				elements[13] * elements[2] * elements[11] +
				elements[13] * elements[3] * elements[10];

			tempo[5] = elements[0] * elements[10] * elements[15] -
				elements[0] * elements[11] * elements[14] -
				elements[8] * elements[2] * elements[15] +
				elements[8] * elements[3] * elements[14] +
				elements[12] * elements[2] * elements[11] -
				elements[12] * elements[3] * elements[10];

			tempo[9] = -elements[0] * elements[9] * elements[15] +
				elements[0] * elements[11] * elements[13] +
				elements[8] * elements[1] * elements[15] -
				elements[8] * elements[3] * elements[13] -
				elements[12] * elements[1] * elements[11] +
				elements[12] * elements[3] * elements[9];

			tempo[13] = elements[0] * elements[9] * elements[14] -
				elements[0] * elements[10] * elements[13] -
				elements[8] * elements[1] * elements[14] +
				elements[8] * elements[2] * elements[13] +
				elements[12] * elements[1] * elements[10] -
				elements[12] * elements[2] * elements[9];

			tempo[2] = elements[1] * elements[6] * elements[15] -
				elements[1] * elements[7] * elements[14] -
				elements[5] * elements[2] * elements[15] +
				elements[5] * elements[3] * elements[14] +
				elements[13] * elements[2] * elements[7] -
				elements[13] * elements[3] * elements[6];

			tempo[6] = -elements[0] * elements[6] * elements[15] +
				elements[0] * elements[7] * elements[14] +
				elements[4] * elements[2] * elements[15] -
				elements[4] * elements[3] * elements[14] -
				elements[12] * elements[2] * elements[7] +
				elements[12] * elements[3] * elements[6];

			tempo[10] = elements[0] * elements[5] * elements[15] -
				elements[0] * elements[7] * elements[13] -
				elements[4] * elements[1] * elements[15] +
				elements[4] * elements[3] * elements[13] +
				elements[12] * elements[1] * elements[7] -
				elements[12] * elements[3] * elements[5];

			tempo[14] = -elements[0] * elements[5] * elements[14] +
				elements[0] * elements[6] * elements[13] +
				elements[4] * elements[1] * elements[14] -
				elements[4] * elements[2] * elements[13] -
				elements[12] * elements[1] * elements[6] +
				elements[12] * elements[2] * elements[5];

			tempo[3] = -elements[1] * elements[6] * elements[11] +
				elements[1] * elements[7] * elements[10] +
				elements[5] * elements[2] * elements[11] -
				elements[5] * elements[3] * elements[10] -
				elements[9] * elements[2] * elements[7] +
				elements[9] * elements[3] * elements[6];

			tempo[7] = elements[0] * elements[6] * elements[11] -
				elements[0] * elements[7] * elements[10] -
				elements[4] * elements[2] * elements[11] +
				elements[4] * elements[3] * elements[10] +
				elements[8] * elements[2] * elements[7] -
				elements[8] * elements[3] * elements[6];

			tempo[11] = -elements[0] * elements[5] * elements[11] +
				elements[0] * elements[7] * elements[9] +
				elements[4] * elements[1] * elements[11] -
				elements[4] * elements[3] * elements[9] -
				elements[8] * elements[1] * elements[7] +
				elements[8] * elements[3] * elements[5];

			tempo[15] = elements[0] * elements[5] * elements[10] -
				elements[0] * elements[6] * elements[9] -
				elements[4] * elements[1] * elements[10] +
				elements[4] * elements[2] * elements[9] +
				elements[8] * elements[1] * elements[6] -
				elements[8] * elements[2] * elements[5];

			float determinant = elements[0] * tempo[0] + elements[1] * tempo[4] + elements[2] * tempo[8] + elements[3] * tempo[12];
			determinant = 1.0f / determinant;

			for (unsigned int i = 0; i < 4 * 4; i++)
				elements[i] = tempo[i] * determinant;
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