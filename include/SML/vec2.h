#pragma once
#pragma warning(push)
#pragma warning(disable : 4804) // unsafe use of type 'bool'

namespace sml {

    template<typename T = float>
    class basic_vector_2
    {
    public:
        union {
        
            struct
            {
                T elements[2];
            };
            
            struct
            {
                T x, y;
            };
        
        };
    public:
        basic_vector_2()
            : x(static_cast<T>(0)),
            y(static_cast<T>(0))
        {
        }
        
        basic_vector_2(T scalar)
            : x(scalar),
            y(scalar)
        {
        }
        
        basic_vector_2(T x, T y)
            : x(x),
            y(y)
        {
        }
        
        T& operator[](int index)
        {
            return elements[index];
        }
        
        const T& operator[](int index) const
        {
            return elements[index];
        }
        
        template<typename U = float>
        void operator+=(const basic_vector_2<U>& other)
        {
            this->x += static_cast<T>(other.x);
            this->y += static_cast<T>(other.y);
        }
        
        template<typename U = float>
        void operator+=(U scalar)
        {
            x += static_cast<T>(scalar);
            y += static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator-=(const basic_vector_2<U>& other)
        {
            this->x -= static_cast<T>(other.x);
            this->y -= static_cast<T>(other.y);
        }
        
        template<typename U = float>
        void operator-=(U scalar)
        {
            x -= static_cast<T>(scalar);
            y -= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator*=(const basic_vector_2<U>& other)
        {
            this->x *= static_cast<T>(other.x);
            this->y *= static_cast<T>(other.y);
        }
        
        template<typename U = float>
        void operator*=(U scalar)
        {
            x *= static_cast<T>(scalar);
            y *= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        void operator/=(const basic_vector_2<U>& other)
        {
            this->x /= static_cast<T>(other.x);
            this->y /= static_cast<T>(other.y);
        }
        
        template<typename U = float>
        void operator/=(U scalar)
        {
            x /= static_cast<T>(scalar);
            y /= static_cast<T>(scalar);
        }
        
        template<typename U = float>
        T dot(const basic_vector_2<U>& other) const
        {
            return this->x * static_cast<T>(other.x) + 
                   this->y * static_cast<T>(other.y);
        }
        
        T* data()
        {
            return &elements[0];
        }
    };

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator+(basic_vector_2<T> lhs, const basic_vector_2<U>& rhs)
    {
        lhs.x += static_cast<T>(rhs.x);
        lhs.y += static_cast<T>(rhs.y);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator+(basic_vector_2<T> lhs, U scalar)
    {
        lhs.x += static_cast<T>(scalar);
        lhs.y += static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator-(basic_vector_2<T> lhs, const basic_vector_2<U>& rhs)
    {
        lhs.x -= static_cast<T>(rhs.x);
        lhs.y -= static_cast<T>(rhs.y);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator-(basic_vector_2<T> lhs, U scalar)
    {
        lhs.x -= static_cast<T>(scalar);
        lhs.y -= static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator*(basic_vector_2<T> lhs, const basic_vector_2<U>& rhs)
    {
        lhs.x *= static_cast<T>(rhs.x);
        lhs.y *= static_cast<T>(rhs.y);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator*(basic_vector_2<T> lhs, U scalar)
    {
        lhs.x *= static_cast<T>(scalar);
        lhs.y *= static_cast<T>(scalar);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator/(basic_vector_2<T> lhs, const basic_vector_2<U>& rhs)
    {
        lhs.x /= static_cast<T>(rhs.x);
        lhs.y /= static_cast<T>(rhs.y);

        return lhs;
    }

    template<typename T = float, typename U = float>
    basic_vector_2<T> operator/(basic_vector_2<T> lhs, U scalar)
    {
        lhs.x /= static_cast<T>(scalar);
        lhs.y /= static_cast<T>(scalar);

        return lhs;
    }

    typedef basic_vector_2<bool>     bvec2;
    typedef basic_vector_2<int>      ivec2;
    typedef basic_vector_2<unsigned> uvec2;
    typedef basic_vector_2<float>    vec2;
    typedef basic_vector_2<double>   dvec2;
}

#pragma warning(pop)
