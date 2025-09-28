#ifndef VECTOR_H
#define VECTOR_H
template<typename T, size_t N>
struct Vector
{
    T data[N];
};

template<typename T, size_t N, typename Op>
Vector<T, N>  ElementWiseOperation(Vector<T,N> v0, Vector<T,N> v1, Op op);
//Operators

template<typename T, size_t N>
Vector<T, N> operator +(Vector<T,N> v0, Vector<T,N> v1);
template<typename T, size_t N>
Vector<T, N> operator -(Vector<T,N> v0, Vector<T,N> v1);
template<typename T, size_t N>
Vector<T, N> operator *(Vector<T,N> v0, Vector<T,N> v1);
//Scalar multiplication
template<typename T, size_t N>
Vector<T, N> operator *(T scalar, Vector<T,N> v);

typedef Vector<float, 3> Vector3;
typedef Vector<float, 4> Vector4;

typedef Vector<int, 3> Vector3i;
typedef Vector<int, 4> Vector4i;

//Math functions

/// Dot product of 2 vectors of the same dimensionality and data type.
/// @return
template<typename T, size_t N>
T Dot(Vector<T, N> v0, Vector<T, N> v1);


/// Cross product of 2 vectors. Only implemented for 3D
/// Order of vectors matters!! Cross product is anti-commutative:
/// a x b = -b x a
/// @param v0 a
/// @param v1 b
/// @return Cross product of the 2 vectors.
template <typename T>
Vector<T, 3> Cross(Vector<T, 3> v0, Vector<T, 3> v1);


#endif //VECTOR_H
