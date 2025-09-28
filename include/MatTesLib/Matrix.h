#ifndef MATRIX_H
#define MATRIX_H
#include <array>
#include <string>
#include <vector>
#include <functional>
#include "MatTesLib/Quaternion.h"
#include "MatTesLib/Vector.h"
namespace Matrix
{
    enum precision
    {
        lowp,
        mediump,
        highp,
        defaultp = highp
    };
    template<size_t C, size_t R, typename T, precision Q = defaultp>
    struct matrix
    {
        T data[C][R]; //Column major

        /// Pretty stringified version of the matrix
        /// @return
        std::string ToString();
        bool operator==(const matrix& m) const;
    };

    /// Preform a member wise operation on 2 identically sized matrices.
    /// @return Result of member wise operation on 2 matrices
    template <size_t C, size_t R, typename T, precision Q, typename Op>
    constexpr matrix<C, R, T, Q> ElementWiseOperation(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1, Op op);

    template<size_t C, size_t R, typename T, precision Q = defaultp>
    matrix<C, R, T, Q> operator+(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1);
    template<size_t C, size_t R, typename T, precision Q = defaultp>
    matrix<C, R, T, Q> operator-(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1);

    template<size_t CR, size_t R1, typename T, precision Q1, size_t C2, precision Q2>
    constexpr matrix<CR, R1, T> operator * (matrix<CR, R1, T, Q1> a, matrix<C2, CR, T, Q2> b);

    template<size_t C, size_t R, typename T,  precision Q>
    constexpr matrix<C, R, T, Q> operator* (T scalar, matrix<C, R, T, Q>& m);

    template<size_t C, size_t R, typename T,  precision Q>
    constexpr Vector<T, R> operator * (Vector<T, R>, const matrix<C, R, T, Q>& m);

    template<size_t C, size_t R, typename T,  precision Q>
    constexpr matrix<C, R, T, Q> Transpose(const matrix<C, R, T, Q>& m);

    template<size_t C, size_t R, typename T,  precision Q>
    constexpr matrix<C, R, T, Q> Inverse(const matrix<C, R, T, Q>& m);


    //Basic sized matrices that are likely to be used
    typedef matrix<2, 2, float> mat2;
    typedef matrix<2, 2, float> mat2x2;

    typedef matrix<3, 3, float> mat3;
    typedef matrix<3, 3, float> mat3x3;

    typedef matrix<4, 4, float> mat4;
    typedef matrix<4, 4, float> mat4x4;


    /// Creates an Identity matrix.
    /// @return 4x4 matrix
    static mat4 Identity();

    /// Creates a translation matrix.
    /// @param x X translation
    /// @param y Y translation
    /// @param z Z translation
    /// @return 4x4 matrix
    static mat4 Translation(float x, float y, float z);

    /// Creates a Scaling matrix with scaling along separate axis.
    /// @param x
    /// @param y
    /// @param z
    /// @return
    static mat4 Scale(float x = 1, float y = 1, float z = 1);

    /// Creates a scaling matrix with the same scaling along each axis.
    /// @param s Uniform Scale
    /// @return
    static mat4 UniformScale(float s);

    static mat4 RotationFromQuaternion(Quaternion q);

}




#endif //MATRIX_H
