#pragma once

#include "utils.h"
#include "vec4.h"

namespace sml {

    template<typename T>
    class basic_matrix_4by4
    {
    public:
        union
        {
            T elements[16];
            
            struct
            {
                basic_vector_4<T> columns[4];
            };
        };
    public:
        basic_matrix_4by4()
        {
            memset(elements, 0, sizeof(T) * 16);
        }

        basic_matrix_4by4(T diagonal)
        {
            memset(elements, 0, sizeof(T) * 16);
            
            columns[0][0] = diagonal;
            columns[1][1] = diagonal;
            columns[2][2] = diagonal;
            columns[3][3] = diagonal;
        }

        static basic_matrix_4by4<T> identity()
        {
            return basic_matrix_4by4<T>(static_cast<T>(1.0));
        }
        
        static basic_matrix_4by4<T> orthographic(T left, T right, T bottom, T top, T near, T far)
        {
            basic_matrix_4by4<T> result = basic_matrix_4by4<T>::identity();
            
            result[0][0] = static_cast<T>(2.0)  / (right - left);
            result[1][1] = static_cast<T>(2.0)  / (top - bottom);
            result[2][2] = static_cast<T>(-2.0) / (far - near);
            
            result[3][0] = -(right + left) / (right - left);
            result[3][1] = -(top + bottom) / (top - bottom);
            result[3][2] = -(far + near)   / (far - near);
            
            return result;
        }
        
        static basic_matrix_4by4<T> perspective(T fov, T aspectRatio, T near, T far)
        {
            basic_matrix_4by4<T> result(static_cast<T>(0));
            
            T tanHalfFov = tan(to_radians(fov * static_cast<T>(0.5)));
            
            result[0][0] = static_cast<T>(1.0) / (aspectRatio * tanHalfFov);
            result[1][1] = static_cast<T>(1.0) / tanHalfFov;
            result[2][2] = -(far + near) / (far - near);
            
            result[2][3] = static_cast<T>(-1.0);
            
            result[3][2] = -(static_cast<T>(2.0) * far * near) / (far - near);
            
            return result;
        }
        
        basic_vector_4<T>& operator[](size_t column)
        {
            return columns[column];
        }
        
        const basic_vector_4<T>& operator[](size_t column) const
        {
            return columns[column];
        }
        
        T* data()
        {
            return &elements[0];
        }

        template<typename U = float>
        void operator*=(const basic_matrix_4by4<U>& other)
        {
            basic_matrix_4by4<T> result = *this;

            result[0] = columns[0] * other[0][0] + 
                        columns[1] * other[0][1] + 
                        columns[2] * other[0][2] + 
                        columns[3] * other[0][3];

            result[1] = columns[0] * other[1][0] + 
                        columns[1] * other[1][1] + 
                        columns[2] * other[1][2] + 
                        columns[3] * other[1][3];

            result[2] = columns[0] * other[2][0] + 
                        columns[1] * other[2][1] + 
                        columns[2] * other[2][2] + 
                        columns[3] * other[2][3];

            result[3] = columns[0] * other[3][0] + 
                        columns[1] * other[3][1] + 
                        columns[2] * other[3][2] + 
                        columns[3] * other[3][3];

            columns[0] = result.columns[0];
            columns[1] = result.columns[1];
            columns[2] = result.columns[2];
            columns[3] = result.columns[3];
        }

        template<typename U = float>
        void translate(const basic_vector_3<U>& translation)
        {
            columns[3][0] += static_cast<T>(translation[0]);
            columns[3][1] += static_cast<T>(translation[1]);
            columns[3][2] += static_cast<T>(translation[2]);
        }
        
        template<typename U = float>
        void scale(const basic_vector_3<U>& scalars)
        {
            columns[0][0] *= static_cast<T>(scalars[0]);
            columns[1][1] *= static_cast<T>(scalars[1]);
            columns[2][2] *= static_cast<T>(scalars[2]);
        }
        
        template<typename U = float>
        void rotate(T angle, const basic_vector_3<U>& axis)
        {
            basic_matrix_4by4<T> rotation(static_cast<T>(1.0));
            
            T r = to_radians(angle);
            T c = cos(r);
            T s = sin(r);
            T omc = static_cast<T>(1.0) - c;
            
            T x = axis.x;
            T y = axis.y;
            T z = axis.z;
            
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
            T tempo[16];
            
            tempo[0] =   elements[5]  * elements[10] * elements[15] -
                         elements[5]  * elements[11] * elements[14] -
                         elements[9]  * elements[6]  * elements[15] +
                         elements[9]  * elements[7]  * elements[14] +
                         elements[13] * elements[6]  * elements[11] -
                         elements[13] * elements[7]  * elements[10];
            
            tempo[4] =  -elements[4]  * elements[10] * elements[15] +
                         elements[4]  * elements[11] * elements[14] +
                         elements[8]  * elements[6]  * elements[15] -
                         elements[8]  * elements[7]  * elements[14] -
                         elements[12] * elements[6]  * elements[11] +
                         elements[12] * elements[7]  * elements[10];
            
            tempo[8] =   elements[4]  * elements[9]  * elements[15] -
                         elements[4]  * elements[11] * elements[13] -
                         elements[8]  * elements[5]  * elements[15] +
                         elements[8]  * elements[7]  * elements[13] +
                         elements[12] * elements[5]  * elements[11] -
                         elements[12] * elements[7]  * elements[9];
            
            tempo[12] = -elements[4]  * elements[9]  * elements[14] +
                         elements[4]  * elements[10] * elements[13] +
                         elements[8]  * elements[5]  * elements[14] -
                         elements[8]  * elements[6]  * elements[13] -
                         elements[12] * elements[5]  * elements[10] +
                         elements[12] * elements[6]  * elements[9];
            
            tempo[1] =  -elements[1]  * elements[10] * elements[15] +
                         elements[1]  * elements[11] * elements[14] +
                         elements[9]  * elements[2]  * elements[15] -
                         elements[9]  * elements[3]  * elements[14] -
                         elements[13] * elements[2]  * elements[11] +
                         elements[13] * elements[3]  * elements[10];
            
            tempo[5] =   elements[0]  * elements[10] * elements[15] -
                         elements[0]  * elements[11] * elements[14] -
                         elements[8]  * elements[2]  * elements[15] +
                         elements[8]  * elements[3]  * elements[14] +
                         elements[12] * elements[2]  * elements[11] -
                         elements[12] * elements[3]  * elements[10];
                         
            tempo[9] =  -elements[0]  * elements[9]  * elements[15] +
                         elements[0]  * elements[11] * elements[13] +
                         elements[8]  * elements[1]  * elements[15] -
                         elements[8]  * elements[3]  * elements[13] -
                         elements[12] * elements[1]  * elements[11] +
                         elements[12] * elements[3]  * elements[9];
            
            tempo[13] =  elements[0]  * elements[9]  * elements[14] -
                         elements[0]  * elements[10] * elements[13] -
                         elements[8]  * elements[1]  * elements[14] +
                         elements[8]  * elements[2]  * elements[13] +
                         elements[12] * elements[1]  * elements[10] -
                         elements[12] * elements[2]  * elements[9];
            
            tempo[2] =   elements[1]  * elements[6] * elements[15] -
                         elements[1]  * elements[7] * elements[14] -
                         elements[5]  * elements[2] * elements[15] +
                         elements[5]  * elements[3] * elements[14] +
                         elements[13] * elements[2] * elements[7]  -
                         elements[13] * elements[3] * elements[6];
            
            tempo[6] =  -elements[0]  * elements[6] * elements[15] +
                         elements[0]  * elements[7] * elements[14] +
                         elements[4]  * elements[2] * elements[15] -
                         elements[4]  * elements[3] * elements[14] -
                         elements[12] * elements[2] * elements[7]  +
                         elements[12] * elements[3] * elements[6];
            
            tempo[10] =  elements[0]  * elements[5] * elements[15] -
                         elements[0]  * elements[7] * elements[13] -
                         elements[4]  * elements[1] * elements[15] +
                         elements[4]  * elements[3] * elements[13] +
                         elements[12] * elements[1] * elements[7]  -
                         elements[12] * elements[3] * elements[5];
            
            tempo[14] = -elements[0]  * elements[5] * elements[14] +
                         elements[0]  * elements[6] * elements[13] +
                         elements[4]  * elements[1] * elements[14] -
                         elements[4]  * elements[2] * elements[13] -
                         elements[12] * elements[1] * elements[6]  +
                         elements[12] * elements[2] * elements[5];
            
            tempo[3] =  -elements[1] * elements[6] * elements[11] +
                         elements[1] * elements[7] * elements[10] +
                         elements[5] * elements[2] * elements[11] -
                         elements[5] * elements[3] * elements[10] -
                         elements[9] * elements[2] * elements[7]  +
                         elements[9] * elements[3] * elements[6];
                        
            tempo[7] =   elements[0] * elements[6] * elements[11] -
                         elements[0] * elements[7] * elements[10] -
                         elements[4] * elements[2] * elements[11] +
                         elements[4] * elements[3] * elements[10] +
                         elements[8] * elements[2] * elements[7]  -
                         elements[8] * elements[3] * elements[6];
            
            tempo[11] = -elements[0] * elements[5] * elements[11] +
                         elements[0] * elements[7] * elements[9]  +
                         elements[4] * elements[1] * elements[11] -
                         elements[4] * elements[3] * elements[9]  -
                         elements[8] * elements[1] * elements[7]  +
                         elements[8] * elements[3] * elements[5];
            
            tempo[15] =  elements[0] * elements[5] * elements[10] -
                         elements[0] * elements[6] * elements[9]  -
                         elements[4] * elements[1] * elements[10] +
                         elements[4] * elements[2] * elements[9]  +
                         elements[8] * elements[1] * elements[6]  -
                         elements[8] * elements[2] * elements[5];
            
            T determinant = elements[0] * tempo[0] + 
                            elements[1] * tempo[4] + 
                            elements[2] * tempo[8] + 
                            elements[3] * tempo[12];
            
            determinant = static_cast<T>(1.0) / determinant;
            
            for (unsigned int i = 0; i < 4 * 4; i++)
                elements[i] = tempo[i] * determinant;
        }
    };

    template<typename T, typename U = float>
    basic_matrix_4by4<T> operator*(const basic_matrix_4by4<T>& lhs, const basic_matrix_4by4<U>& rhs)
    {
        basic_matrix_4by4<T> result;

        result[0] = lhs[0] * static_cast<T>(rhs[0][0]) +
                    lhs[1] * static_cast<T>(rhs[0][1]) +
                    lhs[2] * static_cast<T>(rhs[0][2]) +
                    lhs[3] * static_cast<T>(rhs[0][3]);

        result[1] = lhs[0] * static_cast<T>(rhs[1][0]) +
                    lhs[1] * static_cast<T>(rhs[1][1]) +
                    lhs[2] * static_cast<T>(rhs[1][2]) +
                    lhs[3] * static_cast<T>(rhs[1][3]);

        result[2] = lhs[0] * static_cast<T>(rhs[2][0]) +
                    lhs[1] * static_cast<T>(rhs[2][1]) +
                    lhs[2] * static_cast<T>(rhs[2][2]) +
                    lhs[3] * static_cast<T>(rhs[2][3]);

        result[3] = lhs[0] * static_cast<T>(rhs[3][0]) +
                    lhs[1] * static_cast<T>(rhs[3][1]) +
                    lhs[2] * static_cast<T>(rhs[3][2]) +
                    lhs[3] * static_cast<T>(rhs[3][3]);

        return result;
    }

    typedef basic_matrix_4by4<float>  mat4;
    typedef basic_matrix_4by4<double> dmat4;
}
