#pragma once
namespace Matrix {
    template <size_t C, size_t R, typename T, precision Q>
        bool matrix<C, R, T, Q>::operator==(const matrix& m) const
    {
        return data == m.data;
    }

    template <size_t C, size_t R, typename T, precision Q>
    matrix<C, R, T, Q> operator+(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1)
    {
        return  ElementWiseOperation(m0, m1, [](T a, T b) constexpr { return a + b; });;
    }

    template <size_t C, size_t R, typename T, precision Q>
    matrix<C, R, T, Q> operator-(const matrix<C, R, T, Q>& m0, const matrix<C, R, T, Q>& m1)
    {
        return ElementWiseOperation(m0, m1, [](T a, T b) constexpr { return a - b; });
    }

    template<size_t CR, size_t R1, typename T, precision Q1, size_t C2, precision Q2>
    constexpr matrix<CR, R1, T> operator *(matrix<CR, R1, T, Q1> a, matrix<C2, CR, T, Q2> b)
    {
        matrix<C2, R1, T> result{};

        for (size_t col = 0; col < C2; ++col)
        {
            for (size_t row = 0; row < R1; ++row)
            {
                T sum{};
                for (size_t k = 0; k < CR; ++k)
                {
                    sum += a.data[k][row] * b.data[col][k];
                }
                result.data[col][row] = sum;
            }
        }
        return result;
    }

    template <size_t C, size_t R, typename T, precision Q>
    constexpr matrix<C, R, T, Q> operator*(T scalar, matrix<C, R, T, Q>& m)
    {
        matrix<C, R, T, Q> result{};
        for (size_t col = 0; col < C; ++col)
        {
            for (size_t row = 0; row < R; ++row)
            {
                result[col][row] = scalar * m.data[col][row];
            }
        }
        return result;
    }

    template <size_t C, size_t R, typename T, precision Q>
    constexpr Vector<T, R> operator*(Vector<T, R> v, const matrix<C, R, T, Q>& m)
    {
        Vector<T, R> result{};
        for (size_t col = 0; col < C; ++col)
        {
            T accum{};
            for (size_t row = 0; row < R; ++row)
            {
                accum += v[col] * m.data[col][row];
            }
            result[col] = accum;
        }
        return result;
    }
}