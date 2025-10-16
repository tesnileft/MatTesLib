//Operators
#pragma once
template <typename T, size_t N>
    Vector<T, N> operator+(Vector<T, N> v0, Vector<T, N> v1)
    {
        return ElementWiseOperation(v0, v1, [](T a, T b) { return a + b; });
    }

    template <typename T, size_t N>
    Vector<T, N> operator-(Vector<T, N> v0, Vector<T, N> v1)
    {
        return ElementWiseOperation(v0, v1, [](T a, T b) { return a - b; });
    }

    template <typename T, size_t N>
    Vector<T, N> operator*(Vector<T, N> v0, Vector<T, N> v1)
    {
        return ElementWiseOperation(v0, v1, [](T a, T b) { return a * b; });
    }

    template <typename T, size_t N>
    Vector<T, N> operator *(T scalar, Vector<T,N> v)
    {
        Vector<T, N> result;
        for (size_t i = 0; i < N; i++)
        {
            result[i] = scalar * v[i];
        }
        return result;
}
