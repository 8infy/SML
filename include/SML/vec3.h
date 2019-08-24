#pragma once

#include "vec2.h"

#pragma warning(push)
#pragma warning(disable : 4804) // unsafe use of type 'bool'

namespace sml {

    template<typename T>
    class basic_vector_3
    {
    public:
        union {
        
            struct
            {
                T elements[3];
            };
            
            struct
            {
                T x, y, z;
            };
            
            struct
            {
                T r, g, b;
            };
        
        };
    public:
        basic_vector_3()
            : x(static_cast<T>(0)),
            y(static_cast<T>(0)),
            z(static_cast<T>(0))
        {
        }
        
        basic_vector_3(T scalar)
            : x(scalar),
            y(scalar),
            z(scalar)
        {
        }
        
        basic_vector_3(T x, T y, T z)
            : x(x),
            y(y),
            z(z)
        {
        }
        
        template<typename U = float>
        basic_vector_3(const basic_vector_2<U>& vec2)
            : x(static_cast<T>(vec2.x)),
            y(static_cast<T>(vec2.y)),
            z(static_cast<T>(0))
        {
        }
        
        template<typename U = float>
        basic_vector_3(const basic_vector_2<U>& vec2, T z)
            : x(static_cast<T>(vec2.x)),
            y(static_cast<T>(vec2.y)),
            z(z)
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
        void operator+=(const basic_vector_3<U>& other)
        {
            this->x += static_cast<T>(other.x);
            this->y += static_cast<T>(other.y);
            this->z += static_cast<T>(other.z);
        }
        
        template<typename U = float>
        void operator+=(U scalar)
        {
            x += static_cast<T>(scalar);
            y += static_cast<T>(scalar);
            z += static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator-=(const basic_vector_3<U>& other)
        {
            this->x -= static_cast<T>(other.x);
            this->y -= static_cast<T>(other.y);
            this->z -= static_cast<T>(other.z);
        }
        
        template<typename U = float>
        void operator-=(U scalar)
        {
            x -= static_cast<T>(scalar);
            y -= static_cast<T>(scalar);
            z -= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator*=(const basic_vector_3<U>& other)
        {
            this->x *= static_cast<T>(other.x);
            this->y *= static_cast<T>(other.y);
            this->z *= static_cast<T>(other.z);
        }
        
        template<typename U = float>
        void operator*=(U scalar)
        {
            x *= static_cast<T>(scalar);
            y *= static_cast<T>(scalar);
            z *= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator/=(const basic_vector_3<U>& other)
        {
            this->x /= static_cast<T>(other.x);
            this->y /= static_cast<T>(other.y);
            this->z /= static_cast<T>(other.z);
        }
        
        template<typename U = float>
        void operator/=(U scalar)
        {
            x /= static_cast<T>(scalar);
            y /= static_cast<T>(scalar);
            z /= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        T dot(const basic_vector_3<U>& other) const
        {
            return this->x * static_cast<T>(other.x) + 
                   this->y * static_cast<T>(other.y) + 
                   this->z * static_cast<T>(other.z);
        }
        
        template<typename U = float>
        basic_vector_3<T> cross(const basic_vector_3<U>& other) const
        {
            return basic_vector_3<T>(
                this->y * static_cast<T>(other.z) -
                this->z * static_cast<T>(other.y),
                this->z * static_cast<T>(other.x) -
                this->x * static_cast<T>(other.z),
                this->x * static_cast<T>(other.y) -
                this->y * static_cast<T>(other.x)
            );
        }
        
        T* data()
        {
            return &elements[0];
        }
    };

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator+(basic_vector_3<T> lhs, const basic_vector_3<U>& rhs)
    {
        lhs.x += static_cast<T>(rhs.x);
        lhs.y += static_cast<T>(rhs.y);
        lhs.z += static_cast<T>(rhs.z);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator+(basic_vector_3<T> lhs, U scalar)
    {
        lhs.x += static_cast<T>(scalar);
        lhs.y += static_cast<T>(scalar);
        lhs.z += static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator-(basic_vector_3<T> lhs, const basic_vector_3<U>& rhs)
    {
        lhs.x -= static_cast<T>(rhs.x);
        lhs.y -= static_cast<T>(rhs.y);
        lhs.z -= static_cast<T>(rhs.z);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator-(basic_vector_3<T> lhs, U scalar)
    {
        lhs.x -= static_cast<T>(scalar);
        lhs.y -= static_cast<T>(scalar);
        lhs.z -= static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator*(basic_vector_3<T> lhs, const basic_vector_3<U>& rhs)
    {
        lhs.x *= static_cast<T>(rhs.x);
        lhs.y *= static_cast<T>(rhs.y);
        lhs.z *= static_cast<T>(rhs.z);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator*(basic_vector_3<T> lhs, U scalar)
    {
        lhs.x *= static_cast<T>(scalar);
        lhs.y *= static_cast<T>(scalar);
        lhs.z *= static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator/(basic_vector_3<T> lhs, const basic_vector_3<U>& rhs)
    {
        lhs.x /= static_cast<T>(rhs.x);
        lhs.y /= static_cast<T>(rhs.y);
        lhs.z /= static_cast<T>(rhs.z);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_3<T> operator/(basic_vector_3<T> lhs, U scalar)
    {
        lhs.x /= static_cast<T>(scalar);
        lhs.y /= static_cast<T>(scalar);
        lhs.z /= static_cast<T>(scalar);

        return lhs;
    }

    typedef basic_vector_3<bool>     bvec3;
    typedef basic_vector_3<int>      ivec3;
    typedef basic_vector_3<unsigned> uvec3;
    typedef basic_vector_3<float>    vec3;
    typedef basic_vector_3<double>   dvec3;
}

#pragma warning(pop)
