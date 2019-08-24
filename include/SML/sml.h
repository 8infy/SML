#pragma once

/*----Misc----*/
#include <cmath>
#include "defines.h"
#include "utils.h"
/*----Vectors----*/
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
/*----Matricies----*/
#include "mat4.h"

#pragma warning(push)
#pragma warning(disable : 4804) // unsafe use of type 'bool'

/*----Functions----*/
namespace sml {

    template<typename T = float,  typename U = float>
    inline float dot(const basic_vector_2<T>& lhs, const basic_vector_2<U>& rhs)
    {
        return static_cast<float>(lhs.x) * rhs.x + 
               static_cast<float>(lhs.y) * rhs.y;
    }
    
    template<typename T = float,  typename U = float>
    inline float dot(const basic_vector_3<T>& lhs, const basic_vector_3<U>& rhs)
    {
        return static_cast<float>(lhs.x) * rhs.x + 
               static_cast<float>(lhs.y) * rhs.y + 
               static_cast<float>(lhs.z) * rhs.z;
    }
    
    template<typename T = float,  typename U = float>
    inline float dot(const basic_vector_4<T>& lhs, const basic_vector_4<U>& rhs)
    {
        return static_cast<float>(lhs.x) * rhs.x + 
               static_cast<float>(lhs.y) * rhs.y + 
               static_cast<float>(lhs.z) * rhs.z + 
               static_cast<float>(lhs.w) * rhs.w;
    }
    
    template<typename T = float, typename U = float>
    inline vec3 cross(const basic_vector_3<T>& lhs, const basic_vector_3<U>& rhs)
    {
        return vec3(static_cast<float>(lhs.y) * rhs.z - 
                    static_cast<float>(lhs.z) * rhs.y,
                    static_cast<float>(lhs.z) * rhs.x - 
                    static_cast<float>(lhs.x) * rhs.z,
                    static_cast<float>(lhs.x) * rhs.y - 
                    static_cast<float>(lhs.y) * rhs.x);
    }
    
    template<typename T = float>
    inline float magnitude(const basic_vector_2<T>& vec2)
    {
        return static_cast<float>(
            sqrt(vec2.x * vec2.x + 
                 vec2.y * vec2.y)
            );
    }
    
    template<typename T = float>
    inline float magnitude(const basic_vector_3<T>& vec3)
    {
        return static_cast<float>(
            sqrt(vec3.x * vec3.x +
                 vec3.y * vec3.y + 
                 vec3.z * vec3.z)
            );
    }
    
    template<typename T = float>
    inline vec2 normalize(const basic_vector_2<T>& vec)
    {
        float len = magnitude(vec);
        
        return vec2(vec.x / len, vec.y / len);
    }
    
    template<typename T = float>
    inline vec3 normalize(const basic_vector_3<T>& vec)
    {
        float len = magnitude(vec);
        
        return vec3(vec.x / len, vec.y / len, vec.z / len);
    }

    template<typename T = float, typename U = float>
    inline basic_matrix_4by4<T> translate(const basic_matrix_4by4<T>& matrix, const basic_vector_3<U>& translation)
    {
        basic_matrix_4by4<T> result = matrix;
        result.translate(translation);
        
        return result;
    }
    
    template<typename T = float, typename U = float>
    inline basic_matrix_4by4<T> scale(const basic_matrix_4by4<T>& matrix, const basic_vector_3<U>& scalars)
    {
        basic_matrix_4by4<T> result = matrix;
        result.scale(scalars);
        
        return result;
    }
    
    template<typename T = float, typename U = float>
    inline basic_matrix_4by4<T> rotate(const basic_matrix_4by4<T>& matrix, float angle, const basic_vector_3<U>& axis)
    {
        basic_matrix_4by4<T> rotation(static_cast<T>(1.0));
        
        T r = to_radians(angle);
        T c = cos(r);
        T s = sin(r);
        T omc = static_cast<T>(1.0) - c;
        
        T x = static_cast<T>(axis.x);
        T y = static_cast<T>(axis.y);
        T z = static_cast<T>(axis.z);
        
        rotation[0][0] = x * x * omc + c;
        rotation[0][1] = x * y * omc + z * s;
        rotation[0][2] = x * z * omc - y * s;
        
        rotation[1][0] = x * y * omc - z * s;
        rotation[1][1] = y * y * omc + c;
        rotation[1][2] = y * z * omc + x * s;
        
        rotation[2][0] = x * z * omc + y * s;
        rotation[2][1] = y * z * omc - x * s;
        rotation[2][2] = z * z * omc + c;
        
        basic_matrix_4by4<T> result = matrix;
        
        result *= rotation;
        
        return result;
    }
    
    template<typename T = float>
    inline basic_matrix_4by4<T> orthographic(float left, float right, float bottom, float top, float near, float far)
    {
        basic_matrix_4by4<T> result(static_cast<T>(1.0));
        
        result[0][0] =  static_cast<T>(2.0)  / (right - left);
        result[1][1] =  static_cast<T>(2.0)  / (top - bottom);
        result[2][2] =  static_cast<T>(-2.0) / (far - near);
        
        result[3][0] = -(right + left) / (right - left);
        result[3][1] = -(top + bottom) / (top - bottom);
        result[3][2] = -(far + near)   / (far - near);
        
        return result;
    }
    
    template<typename T = float>
    inline basic_matrix_4by4<T> perspective(float fov, float aspectRatio, float near, float far)
    {
        basic_matrix_4by4<T> result(static_cast<T>(0.0));
        
        float tanHalfFov = tan(to_radians(fov * static_cast<T>(0.5)));
        
        result[0][0] = static_cast<T>(1.0) / (aspectRatio * tanHalfFov);
        result[1][1] = static_cast<T>(1.0) / tanHalfFov;
        result[2][2] = -(far + near) / (far - near);
        
        result[2][3] = static_cast<T>(-1.0);
        
        result[3][2] = -(static_cast<T>(2.0) * far * near) / (far - near);
        
        return result;
    }
    
    template<typename T = float>
    inline basic_matrix_4by4<T> lookAt(const vec3& camera, const vec3& target, const vec3& up)
    {
        basic_matrix_4by4<T> result(static_cast<T>(1.0));
        
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

    template<typename T = float>
    inline basic_matrix_4by4<T> inverse(basic_matrix_4by4<T> matrix)
    {
        float tempo[16];
        
        tempo[0] =   matrix.elements[5]  * matrix.elements[10] * matrix.elements[15] -
                     matrix.elements[5]  * matrix.elements[11] * matrix.elements[14] -
                     matrix.elements[9]  * matrix.elements[6]  * matrix.elements[15] +
                     matrix.elements[9]  * matrix.elements[7]  * matrix.elements[14] +
                     matrix.elements[13] * matrix.elements[6]  * matrix.elements[11] -
                     matrix.elements[13] * matrix.elements[7]  * matrix.elements[10];
        
        tempo[4] =  -matrix.elements[4]  * matrix.elements[10] * matrix.elements[15] +
                     matrix.elements[4]  * matrix.elements[11] * matrix.elements[14] +
                     matrix.elements[8]  * matrix.elements[6]  * matrix.elements[15] -
                     matrix.elements[8]  * matrix.elements[7]  * matrix.elements[14] -
                     matrix.elements[12] * matrix.elements[6]  * matrix.elements[11] +
                     matrix.elements[12] * matrix.elements[7]  * matrix.elements[10];
        
        tempo[8] =   matrix.elements[4]  * matrix.elements[9]  * matrix.elements[15] -
                     matrix.elements[4]  * matrix.elements[11] * matrix.elements[13] -
                     matrix.elements[8]  * matrix.elements[5]  * matrix.elements[15] +
                     matrix.elements[8]  * matrix.elements[7]  * matrix.elements[13] +
                     matrix.elements[12] * matrix.elements[5]  * matrix.elements[11] -
                     matrix.elements[12] * matrix.elements[7]  * matrix.elements[9];
                     
        tempo[12] = -matrix.elements[4]  * matrix.elements[9]  * matrix.elements[14] +
                     matrix.elements[4]  * matrix.elements[10] * matrix.elements[13] +
                     matrix.elements[8]  * matrix.elements[5]  * matrix.elements[14] -
                     matrix.elements[8]  * matrix.elements[6]  * matrix.elements[13] -
                     matrix.elements[12] * matrix.elements[5]  * matrix.elements[10] +
                     matrix.elements[12] * matrix.elements[6]  * matrix.elements[9];
        
        tempo[1] =  -matrix.elements[1]  * matrix.elements[10] * matrix.elements[15] +
                     matrix.elements[1]  * matrix.elements[11] * matrix.elements[14] +
                     matrix.elements[9]  * matrix.elements[2]  * matrix.elements[15] -
                     matrix.elements[9]  * matrix.elements[3]  * matrix.elements[14] -
                     matrix.elements[13] * matrix.elements[2]  * matrix.elements[11] +
                     matrix.elements[13] * matrix.elements[3]  * matrix.elements[10];
                    
        tempo[5] =   matrix.elements[0]  * matrix.elements[10] * matrix.elements[15] -
                     matrix.elements[0]  * matrix.elements[11] * matrix.elements[14] -
                     matrix.elements[8]  * matrix.elements[2]  * matrix.elements[15] +
                     matrix.elements[8]  * matrix.elements[3]  * matrix.elements[14] +
                     matrix.elements[12] * matrix.elements[2]  * matrix.elements[11] -
                     matrix.elements[12] * matrix.elements[3]  * matrix.elements[10];
                    
        tempo[9] =  -matrix.elements[0]  * matrix.elements[9]  * matrix.elements[15] +
                     matrix.elements[0]  * matrix.elements[11] * matrix.elements[13] +
                     matrix.elements[8]  * matrix.elements[1]  * matrix.elements[15] -
                     matrix.elements[8]  * matrix.elements[3]  * matrix.elements[13] -
                     matrix.elements[12] * matrix.elements[1]  * matrix.elements[11] +
                     matrix.elements[12] * matrix.elements[3]  * matrix.elements[9];
        
        tempo[13] =  matrix.elements[0]  * matrix.elements[9]  * matrix.elements[14] -
                     matrix.elements[0]  * matrix.elements[10] * matrix.elements[13] -
                     matrix.elements[8]  * matrix.elements[1]  * matrix.elements[14] +
                     matrix.elements[8]  * matrix.elements[2]  * matrix.elements[13] +
                     matrix.elements[12] * matrix.elements[1]  * matrix.elements[10] -
                     matrix.elements[12] * matrix.elements[2]  * matrix.elements[9];
        
        tempo[2] =   matrix.elements[1]  * matrix.elements[6] * matrix.elements[15] -
                     matrix.elements[1]  * matrix.elements[7] * matrix.elements[14] -
                     matrix.elements[5]  * matrix.elements[2] * matrix.elements[15] +
                     matrix.elements[5]  * matrix.elements[3] * matrix.elements[14] +
                     matrix.elements[13] * matrix.elements[2] * matrix.elements[7]  -
                     matrix.elements[13] * matrix.elements[3] * matrix.elements[6];
        
        tempo[6] =  -matrix.elements[0]  * matrix.elements[6] * matrix.elements[15] +
                     matrix.elements[0]  * matrix.elements[7] * matrix.elements[14] +
                     matrix.elements[4]  * matrix.elements[2] * matrix.elements[15] -
                     matrix.elements[4]  * matrix.elements[3] * matrix.elements[14] -
                     matrix.elements[12] * matrix.elements[2] * matrix.elements[7]  +
                     matrix.elements[12] * matrix.elements[3] * matrix.elements[6];
        
        tempo[10] =  matrix.elements[0]  * matrix.elements[5] * matrix.elements[15] -
                     matrix.elements[0]  * matrix.elements[7] * matrix.elements[13] -
                     matrix.elements[4]  * matrix.elements[1] * matrix.elements[15] +
                     matrix.elements[4]  * matrix.elements[3] * matrix.elements[13] +
                     matrix.elements[12] * matrix.elements[1] * matrix.elements[7]  -
                     matrix.elements[12] * matrix.elements[3] * matrix.elements[5];
        
        tempo[14] = -matrix.elements[0]  * matrix.elements[5] * matrix.elements[14] +
                     matrix.elements[0]  * matrix.elements[6] * matrix.elements[13] +
                     matrix.elements[4]  * matrix.elements[1] * matrix.elements[14] -
                     matrix.elements[4]  * matrix.elements[2] * matrix.elements[13] -
                     matrix.elements[12] * matrix.elements[1] * matrix.elements[6]  +
                     matrix.elements[12] * matrix.elements[2] * matrix.elements[5];
        
        tempo[3] =  -matrix.elements[1] * matrix.elements[6] * matrix.elements[11] +
                     matrix.elements[1] * matrix.elements[7] * matrix.elements[10] +
                     matrix.elements[5] * matrix.elements[2] * matrix.elements[11] -
                     matrix.elements[5] * matrix.elements[3] * matrix.elements[10] -
                     matrix.elements[9] * matrix.elements[2] * matrix.elements[7]  +
                     matrix.elements[9] * matrix.elements[3] * matrix.elements[6];
        
        tempo[7] =   matrix.elements[0] * matrix.elements[6] * matrix.elements[11] -
                     matrix.elements[0] * matrix.elements[7] * matrix.elements[10] -
                     matrix.elements[4] * matrix.elements[2] * matrix.elements[11] +
                     matrix.elements[4] * matrix.elements[3] * matrix.elements[10] +
                     matrix.elements[8] * matrix.elements[2] * matrix.elements[7]  -
                     matrix.elements[8] * matrix.elements[3] * matrix.elements[6];
        
        tempo[11] = -matrix.elements[0] * matrix.elements[5] * matrix.elements[11] +
                     matrix.elements[0] * matrix.elements[7] * matrix.elements[9]  +
                     matrix.elements[4] * matrix.elements[1] * matrix.elements[11] -
                     matrix.elements[4] * matrix.elements[3] * matrix.elements[9]  -
                     matrix.elements[8] * matrix.elements[1] * matrix.elements[7]  +
                     matrix.elements[8] * matrix.elements[3] * matrix.elements[5];
        
        tempo[15] =  matrix.elements[0] * matrix.elements[5] * matrix.elements[10] -
                     matrix.elements[0] * matrix.elements[6] * matrix.elements[9]  -
                     matrix.elements[4] * matrix.elements[1] * matrix.elements[10] +
                     matrix.elements[4] * matrix.elements[2] * matrix.elements[9]  +
                     matrix.elements[8] * matrix.elements[1] * matrix.elements[6]  -
                     matrix.elements[8] * matrix.elements[2] * matrix.elements[5];
        
        T determinant = matrix.elements[0] * tempo[0] + 
                        matrix.elements[1] * tempo[4] + 
                        matrix.elements[2] * tempo[8] + 
                        matrix.elements[3] * tempo[12];

        determinant = static_cast<T>(1.0) / determinant;
        
        for (unsigned int i = 0; i < 4 * 4; i++)
            matrix.elements[i] = tempo[i] * determinant;

        return matrix;
    }
}

#pragma warning(pop)
