#pragma once

/*----Misc----*/
#include "defines.h"
#include "utils.h"
/*----Vectors----*/
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
/*----Matricies----*/
#include "mat4.h"

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
		return sqrt(vec3.x * vec3.x + 
					vec3.y * vec3.y + 
					vec3.z * vec3.z);
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

	inline mat4 translate(const mat4& matrix, const vec3& translation)
	{
		mat4 result = matrix;
		result.translate(translation);

		return result;
	}

	inline mat4 scale(const mat4& matrix, const vec3& scalars)
	{
		mat4 result = matrix;
		result.scale(scalars);

		return result;
	}

	inline mat4 rotate(const mat4& matrix, float angle, const vec3& axis)
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

		mat4 result = matrix;
		
		result *= rotation;
		
		return result;
	}

	inline mat4 orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		mat4 result(1.0f);

		result[0][0] =  2.0f / (right - left);
		result[1][1] =  2.0f / (top - bottom);
		result[2][2] = -2.0f / (far - near);

		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		result[3][2] = -(far + near) / (far - near);

		return result;
	}

	inline mat4 perspective(float fov, float aspectRatio, float near, float far)
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

	inline mat4 lookAt(const vec3& camera, const vec3& target, const vec3&  up)
	{
		mat4 result(1.0f);

		vec3 f = normalize(target - camera);
		vec3 s = cross(f, normalize(up));
		vec3 u = cross(s, f);

		result[0][0] = s.x;
		result[1][0] = s.y;
		result[2][0] = s.z;

		result[0][1] = u.x;
		result[1][1] = u.y;
		result[2][1] = u.z;

		result[0][2] = -f.x;
		result[1][2] = -f.y;
		result[2][2] = -f.z;

		result[3][0] = -dot(s, camera);
		result[3][1] = -dot(u, camera);
		result[3][2] = -dot(f, camera);

		return result;
	}

	inline mat4 inverse(mat4 matrix)
	{
		float tempo[16];

		tempo[0] = matrix.elements[5] * matrix.elements[10] * matrix.elements[15] -
			matrix.elements[5] * matrix.elements[11] * matrix.elements[14] -
			matrix.elements[9] * matrix.elements[6] * matrix.elements[15] +
			matrix.elements[9] * matrix.elements[7] * matrix.elements[14] +
			matrix.elements[13] * matrix.elements[6] * matrix.elements[11] -
			matrix.elements[13] * matrix.elements[7] * matrix.elements[10];

		tempo[4] = -matrix.elements[4] * matrix.elements[10] * matrix.elements[15] +
			matrix.elements[4] * matrix.elements[11] * matrix.elements[14] +
			matrix.elements[8] * matrix.elements[6] * matrix.elements[15] -
			matrix.elements[8] * matrix.elements[7] * matrix.elements[14] -
			matrix.elements[12] * matrix.elements[6] * matrix.elements[11] +
			matrix.elements[12] * matrix.elements[7] * matrix.elements[10];

		tempo[8] = matrix.elements[4] * matrix.elements[9] * matrix.elements[15] -
			matrix.elements[4] * matrix.elements[11] * matrix.elements[13] -
			matrix.elements[8] * matrix.elements[5] * matrix.elements[15] +
			matrix.elements[8] * matrix.elements[7] * matrix.elements[13] +
			matrix.elements[12] * matrix.elements[5] * matrix.elements[11] -
			matrix.elements[12] * matrix.elements[7] * matrix.elements[9];

		tempo[12] = -matrix.elements[4] * matrix.elements[9] * matrix.elements[14] +
			matrix.elements[4] * matrix.elements[10] * matrix.elements[13] +
			matrix.elements[8] * matrix.elements[5] * matrix.elements[14] -
			matrix.elements[8] * matrix.elements[6] * matrix.elements[13] -
			matrix.elements[12] * matrix.elements[5] * matrix.elements[10] +
			matrix.elements[12] * matrix.elements[6] * matrix.elements[9];

		tempo[1] = -matrix.elements[1] * matrix.elements[10] * matrix.elements[15] +
			matrix.elements[1] * matrix.elements[11] * matrix.elements[14] +
			matrix.elements[9] * matrix.elements[2] * matrix.elements[15] -
			matrix.elements[9] * matrix.elements[3] * matrix.elements[14] -
			matrix.elements[13] * matrix.elements[2] * matrix.elements[11] +
			matrix.elements[13] * matrix.elements[3] * matrix.elements[10];

		tempo[5] = matrix.elements[0] * matrix.elements[10] * matrix.elements[15] -
			matrix.elements[0] * matrix.elements[11] * matrix.elements[14] -
			matrix.elements[8] * matrix.elements[2] * matrix.elements[15] +
			matrix.elements[8] * matrix.elements[3] * matrix.elements[14] +
			matrix.elements[12] * matrix.elements[2] * matrix.elements[11] -
			matrix.elements[12] * matrix.elements[3] * matrix.elements[10];

		tempo[9] = -matrix.elements[0] * matrix.elements[9] * matrix.elements[15] +
			matrix.elements[0] * matrix.elements[11] * matrix.elements[13] +
			matrix.elements[8] * matrix.elements[1] * matrix.elements[15] -
			matrix.elements[8] * matrix.elements[3] * matrix.elements[13] -
			matrix.elements[12] * matrix.elements[1] * matrix.elements[11] +
			matrix.elements[12] * matrix.elements[3] * matrix.elements[9];

		tempo[13] = matrix.elements[0] * matrix.elements[9] * matrix.elements[14] -
			matrix.elements[0] * matrix.elements[10] * matrix.elements[13] -
			matrix.elements[8] * matrix.elements[1] * matrix.elements[14] +
			matrix.elements[8] * matrix.elements[2] * matrix.elements[13] +
			matrix.elements[12] * matrix.elements[1] * matrix.elements[10] -
			matrix.elements[12] * matrix.elements[2] * matrix.elements[9];

		tempo[2] = matrix.elements[1] * matrix.elements[6] * matrix.elements[15] -
			matrix.elements[1] * matrix.elements[7] * matrix.elements[14] -
			matrix.elements[5] * matrix.elements[2] * matrix.elements[15] +
			matrix.elements[5] * matrix.elements[3] * matrix.elements[14] +
			matrix.elements[13] * matrix.elements[2] * matrix.elements[7] -
			matrix.elements[13] * matrix.elements[3] * matrix.elements[6];

		tempo[6] = -matrix.elements[0] * matrix.elements[6] * matrix.elements[15] +
			matrix.elements[0] * matrix.elements[7] * matrix.elements[14] +
			matrix.elements[4] * matrix.elements[2] * matrix.elements[15] -
			matrix.elements[4] * matrix.elements[3] * matrix.elements[14] -
			matrix.elements[12] * matrix.elements[2] * matrix.elements[7] +
			matrix.elements[12] * matrix.elements[3] * matrix.elements[6];

		tempo[10] = matrix.elements[0] * matrix.elements[5] * matrix.elements[15] -
			matrix.elements[0] * matrix.elements[7] * matrix.elements[13] -
			matrix.elements[4] * matrix.elements[1] * matrix.elements[15] +
			matrix.elements[4] * matrix.elements[3] * matrix.elements[13] +
			matrix.elements[12] * matrix.elements[1] * matrix.elements[7] -
			matrix.elements[12] * matrix.elements[3] * matrix.elements[5];

		tempo[14] = -matrix.elements[0] * matrix.elements[5] * matrix.elements[14] +
			matrix.elements[0] * matrix.elements[6] * matrix.elements[13] +
			matrix.elements[4] * matrix.elements[1] * matrix.elements[14] -
			matrix.elements[4] * matrix.elements[2] * matrix.elements[13] -
			matrix.elements[12] * matrix.elements[1] * matrix.elements[6] +
			matrix.elements[12] * matrix.elements[2] * matrix.elements[5];

		tempo[3] = -matrix.elements[1] * matrix.elements[6] * matrix.elements[11] +
			matrix.elements[1] * matrix.elements[7] * matrix.elements[10] +
			matrix.elements[5] * matrix.elements[2] * matrix.elements[11] -
			matrix.elements[5] * matrix.elements[3] * matrix.elements[10] -
			matrix.elements[9] * matrix.elements[2] * matrix.elements[7] +
			matrix.elements[9] * matrix.elements[3] * matrix.elements[6];

		tempo[7] = matrix.elements[0] * matrix.elements[6] * matrix.elements[11] -
			matrix.elements[0] * matrix.elements[7] * matrix.elements[10] -
			matrix.elements[4] * matrix.elements[2] * matrix.elements[11] +
			matrix.elements[4] * matrix.elements[3] * matrix.elements[10] +
			matrix.elements[8] * matrix.elements[2] * matrix.elements[7] -
			matrix.elements[8] * matrix.elements[3] * matrix.elements[6];

		tempo[11] = -matrix.elements[0] * matrix.elements[5] * matrix.elements[11] +
			matrix.elements[0] * matrix.elements[7] * matrix.elements[9] +
			matrix.elements[4] * matrix.elements[1] * matrix.elements[11] -
			matrix.elements[4] * matrix.elements[3] * matrix.elements[9] -
			matrix.elements[8] * matrix.elements[1] * matrix.elements[7] +
			matrix.elements[8] * matrix.elements[3] * matrix.elements[5];

		tempo[15] = matrix.elements[0] * matrix.elements[5] * matrix.elements[10] -
			matrix.elements[0] * matrix.elements[6] * matrix.elements[9] -
			matrix.elements[4] * matrix.elements[1] * matrix.elements[10] +
			matrix.elements[4] * matrix.elements[2] * matrix.elements[9] +
			matrix.elements[8] * matrix.elements[1] * matrix.elements[6] -
			matrix.elements[8] * matrix.elements[2] * matrix.elements[5];

		float determinant = matrix.elements[0] * tempo[0] + 
							matrix.elements[1] * tempo[4] + 
							matrix.elements[2] * tempo[8] + 
							matrix.elements[3] * tempo[12];

		determinant = 1.0f / determinant;

		for (unsigned int i = 0; i < 4 * 4; i++)
			matrix.elements[i] = tempo[i] * determinant;

		return matrix;
	}
}