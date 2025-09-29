#include "MatTesLib/Matrix.h"

#include <sstream>
#include <stdexcept>
namespace Matrix
{
    template <size_t C, size_t R, typename T, precision Q, typename Op>
    constexpr matrix<C, R, T, Q> ElementWiseOperation(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1, Op op)
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
    mat4 RotationX(const float degrees)
    {
        mat4 result = Identity();

        return result;

    }
    mat4 RotationY(const float degrees)
    {
        mat4 result = Identity();

        return result;
    }
    mat4 RotationZ(const float degrees)
    {
        mat4 result = Identity();

        return result;
    }

    mat4 RotationFromQuaternion(Quaternion q)
    {
        mat4 result = Identity();

        return result;
    }
}
