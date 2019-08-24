#pragma once

#include "vec2.h"
#include "vec3.h"

#pragma warning(push)
#pragma warning(disable : 4804) // unsafe use of type 'bool'

namespace sml {

    template<typename T>
    class basic_vector_4
    {
    public:
        union {
        
            struct
            {
                T elements[4];
            };
            
            struct
            {
                T x, y, z, w;
            };
            
            struct
            {
                T r, g, b, a;
            };
        
        };
    public:
        basic_vector_4()
            : x(static_cast<T>(0)),
            y(static_cast<T>(0)),
            z(static_cast<T>(0)),
            w(static_cast<T>(1))
        {
        }
        
        basic_vector_4(T scalar)
            : x(scalar),
            y(scalar),
            z(scalar),
            w(scalar)
        {
        }
        
        basic_vector_4(T x, T y, T z, T w)
            : x(x),
            y(y),
            z(z),
            w(w)
        {
        }
        
        template<typename U = float>
        basic_vector_4(const basic_vector_2<U>& vec2) 
            : x(static_cast<T>(vec2.x)),
            y(static_cast<T>(vec2.y)),
            z(static_cast<T>(0)),
            w(static_cast<T>(1))
        {
        }
        
        template<typename U = float>
        basic_vector_4(const basic_vector_2<U>& vec2, T z) 
            : x(static_cast<T>(vec2.x)),
            y(static_cast<T>(vec2.y)),
            z(z), 
            w(static_cast<T>(1))
        {
        }
        
        template<typename U = float>
        basic_vector_4(const basic_vector_2<U>& vec2, T z, T w) 
            : x(static_cast<T>(vec2.x)),
            y(static_cast<T>(vec2.y)),
            z(z), 
            w(w) 
        {
        }
        
        template<typename U = float>
        basic_vector_4(const basic_vector_3<U>& vec3) 
            : x(static_cast<T>(vec3.x)),
            y(static_cast<T>(vec3.y)),
            z(static_cast<T>(vec3.z)),
            w(static_cast<T>(1))
        {
        }
        
        template<typename U = float>
        basic_vector_4(const basic_vector_3<U>& vec3, T w) 
            : x(static_cast<T>(vec3.x)),
            y(static_cast<T>(vec3.y)),
            z(static_cast<T>(vec3.z)),
            w(w) 
        {
        }
        
        T& operator[](size_t index)
        {
            return elements[index];
        }

        const T& operator[](size_t index) const
        {
            return elements[index];
        }
        
        template<typename U = float>
        void operator+=(const basic_vector_4<U>& other)
        {
            this->x += static_cast<T>(other.x);
            this->y += static_cast<T>(other.y);
            this->z += static_cast<T>(other.z);
            this->w += static_cast<T>(other.w);
        }
        
        template<typename U = float>
        void operator+=(U scalar)
        {
            x += static_cast<T>(scalar);
            y += static_cast<T>(scalar);
            z += static_cast<T>(scalar);
            w += static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator-=(const basic_vector_4<U>& other)
        {
            this->x -= static_cast<T>(other.x);
            this->y -= static_cast<T>(other.y);
            this->z -= static_cast<T>(other.z);
            this->w -= static_cast<T>(other.w);
        }
        
        template<typename U = float>
        void operator-=(U scalar)
        {
            x -= static_cast<T>(scalar);
            y -= static_cast<T>(scalar);
            z -= static_cast<T>(scalar);
            w -= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator*=(const basic_vector_4<U>& other)
        {
            this->x *= static_cast<T>(other.x);
            this->y *= static_cast<T>(other.y);
            this->z *= static_cast<T>(other.z);
            this->w *= static_cast<T>(other.w);
        }
        
        template<typename U = float>
        void operator*=(U scalar)
        {
            x *= static_cast<T>(scalar);
            y *= static_cast<T>(scalar);
            z *= static_cast<T>(scalar);
            w *= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator/=(const basic_vector_4<U>& other)
        {
            this->x /= static_cast<T>(other.x);
            this->y /= static_cast<T>(other.y);
            this->z /= static_cast<T>(other.z);
            this->w /= static_cast<T>(other.w);
        }
        
        template<typename U = float>
        void operator/=(U scalar)
        {
            x /= static_cast<T>(scalar);
            y /= static_cast<T>(scalar);
            z /= static_cast<T>(scalar);
            w /= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        T dot(const basic_vector_4<U>& other) const
        {
            return this->x * static_cast<T>(other.x) +
                   this->y * static_cast<T>(other.y) +
                   this->z * static_cast<T>(other.z) +
                   this->w * static_cast<T>(other.w);
        }
        
        T* data()
        {
            return &elements[0];
        }
    };

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator+(basic_vector_4<T> lhs, const basic_vector_4<U>& rhs)
    {
        lhs.x += static_cast<T>(rhs.x);
        lhs.y += static_cast<T>(rhs.y);
        lhs.z += static_cast<T>(rhs.z);
        lhs.w += static_cast<T>(rhs.w);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator+(basic_vector_4<T> lhs, U scalar)
    {
        lhs.x += static_cast<T>(scalar);
        lhs.y += static_cast<T>(scalar);
        lhs.z += static_cast<T>(scalar);
        lhs.w += static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator-(basic_vector_4<T> lhs, const basic_vector_4<U>& rhs)
    {
        lhs.x -= static_cast<T>(rhs.x);
        lhs.y -= static_cast<T>(rhs.y);
        lhs.z -= static_cast<T>(rhs.z);
        lhs.w -= static_cast<T>(rhs.w);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator-(basic_vector_4<T> lhs, U scalar)
    {
        lhs.x -= static_cast<T>(scalar);
        lhs.y -= static_cast<T>(scalar);
        lhs.z -= static_cast<T>(scalar);
        lhs.w -= static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator*(basic_vector_4<T> lhs, const basic_vector_4<U>& rhs)
    {
        lhs.x *= static_cast<T>(rhs.x);
        lhs.y *= static_cast<T>(rhs.y);
        lhs.z *= static_cast<T>(rhs.z);
        lhs.w *= static_cast<T>(rhs.w);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator*(basic_vector_4<T> lhs, U scalar)
    {
        lhs.x *= static_cast<T>(scalar);
        lhs.y *= static_cast<T>(scalar);
        lhs.z *= static_cast<T>(scalar);
        lhs.w *= static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator/(basic_vector_4<T> lhs, const basic_vector_4<U>& rhs)
    {
        lhs.x /= static_cast<T>(rhs.x);
        lhs.y /= static_cast<T>(rhs.y);
        lhs.z /= static_cast<T>(rhs.z);
        lhs.w /= static_cast<T>(rhs.w);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_4<T> operator/(basic_vector_4<T> lhs, U scalar)
    {
        lhs.x /= static_cast<T>(scalar);
        lhs.y /= static_cast<T>(scalar);
        lhs.z /= static_cast<T>(scalar);
        lhs.w /= static_cast<T>(scalar);

        return lhs;
    }

    typedef basic_vector_4<bool>     bvec4;
    typedef basic_vector_4<int>      ivec4;
    typedef basic_vector_4<unsigned> uvec4;
    typedef basic_vector_4<float>    vec4;
    typedef basic_vector_4<double>   dvec4;
}

#pragma warning(pop)
