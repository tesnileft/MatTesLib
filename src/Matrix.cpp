#include "../Matrix.h"

#include <sstream>
#include <stdexcept>
#include <oneapi/tbb/detail/_utils.h>
namespace Matrix
{
    template <size_t C, size_t R, typename T, precision Q, typename Op>
    constexpr matrix<C, R, T, Q> elementWiseOperation(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1, Op op)
    {
        matrix<C, R, T, Q> result{};
        for (int column = 0; column < C; column++)
        {
            for (int row = 0; row < R; row++)
            {
                result.data[column][row] = op(m0.data[column][row], m1.data[column][row]);
            }
        }
        return result;
    }
    template <size_t C, size_t R, typename T, precision Q>
    bool matrix<C, R, T, Q>::operator==(const matrix& m) const
    {
        return data == m.data;
    }

    template <size_t C, size_t R, typename T, precision Q>
    matrix<C, R, T, Q> operator+(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1)
    {
        matrix<C, R, T, Q> result = elementWiseOperation(m0, m1, [](T a, T b) constexpr { return a + b; });
        return result;

    }

    template <size_t C, size_t R, typename T, precision Q>
    matrix<C, R, T, Q> operator-(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1)
    {
        return elementWiseOperation(m0, m1, [](T a, T b) constexpr { return a - b; });
    }

    template<size_t C1, size_t R1, typename T, precision Q1, size_t C2, size_t R2, precision Q2, std::enable_if_t<C1 == R2>>
    constexpr matrix<C2, R1, T> operator *(const matrix<C1, R1, T, Q1> a, const matrix<C2, R2, T, Q2> b)
    {
        matrix<C2, R1, T> result{};

        for (size_t col = 0; col < C2; ++col)
        {
            for (size_t row = 0; row < R1; ++row)
            {
                T sum{};
                for (size_t k = 0; k < C1; ++k)
                {
                    sum += a.data[k][row] * b.data[col][k];
                }
                result.data[col][row] = sum;
            }
        }
        return result;
    }

    template <size_t C, size_t R, typename T, precision Q>
    std::string matrix<C, R, T, Q>::ToString()
    {
        std::ostringstream result{};
        for (int y = 0; y < R; y++)
        {
            for (int x = 0; x < C; x++)
            {
                result << data[x][y] << " ";
            }
            result << "\n";
        }
        return result.str();
    }

    mat4 Identity()
    {
        return{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1};
    }

    mat4 Translation(const float x, const float y, const float z)
    {
        return{
            1, 0, 0,0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            x, y, z, 1
        };
    }

    mat4 Scale(const float x, const float y, const float z)
    {
        return{
            x, 0, 0, 0,
            0, y, 0, 0,
            0, 0, z, 0,
            0, 0, 0, 1}
        ;
    }

    mat4 UniformScale(const float s)
    {
        return Scale(s, s, s);
    }

    mat4 RotationFromQuaternion(Quaternion q)
    {
    }
}
