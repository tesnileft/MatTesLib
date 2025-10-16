#include "MatTesLib/Vector.h"

template<typename T, size_t N, typename Op>
Vector<T, N>  ElementWiseOperation(Vector<T,N> v0, Vector<T,N> v1, Op op)
{
    Vector<T, N> result;
    for (size_t i = 0; i < N; i++)
    {
        result[i] = op(v0[i], v1[i]);
    }
    return result;
}

template <typename T>
Vector<T, 3> Cross(Vector<T, 3> v0, Vector<T, 3> v1)
{
    Vector<T, 3> result{};
    result[0] = v0[1]*v1[2] - v0[2]*v1[1];
    result[1] = v0[2]*v1[0] - v0[0]*v1[2];
    result[2] = v0[0]*v1[1] - v0[1]*v1[0];
    return result;
}

template <typename T, size_t N>
T Dot(Vector<T, N> v0, Vector<T, N> v1)
{
    T result = 0;
    for (size_t i = 0; i < N; i++)
    {
        result += v0[i] * v1[i];
    }
    return result;
}
