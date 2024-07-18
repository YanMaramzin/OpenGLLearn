#pragma once

template<typename T>
class Matrix
{
public:
    // Matrix();
    Matrix(size_t rows, size_t cols);
    explicit Matrix(size_t size);
    // Matrix(const Matrix<T> &matrix);

    ~Matrix();

    void resize(size_t rows, size_t cols);

    size_t rows() const;
    size_t cols() const;
    // void size();

    inline Matrix<T> &operator +=(const Matrix<T> &rhs);
    inline Matrix<T> &operator +=(const T &rhs);

private:
    T *m_data;
    size_t m_rows {0};
    size_t m_cols {0};
};

// template<typename T>
// Matrix<T>::Matrix()
// {
// }

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols)
{
    m_data = new T[m_rows * m_cols];
}

template<typename T>
Matrix<T>::Matrix(size_t size) : m_rows(size), m_cols(size)
{
    m_data = new T[m_rows * m_cols];
}

template<typename T>
Matrix<T>::~Matrix()
{
    delete[] m_data;
}

template<typename T>
size_t Matrix<T>::rows() const
{
    return m_rows;
}

template<typename T>
size_t Matrix<T>::cols() const
{
    return m_cols;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    if (rhs.cols() != m_cols && rhs.rows() != m_rows)
        return *this;

    const auto numElements = m_rows * m_cols;
    for (size_t i = 0;  i < numElements; ++i)
        m_data[i] += rhs.m_data[i];

    return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator+=(const T &rhs)
{
    if (rhs.cols() != m_cols && rhs.rows() != m_rows)
        return *this;

    const auto numElements = m_rows * m_cols;
    for (size_t i = 0;  i < numElements; ++i)
        m_data[i] += rhs;

    return *this;
}

