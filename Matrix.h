#pragma once

#include "Vector.h"

template<typename T>
class Matrix {
private:
    size_t _size;
    Vector<T> *_vectors;
    size_t _vec_size;
public:
    Matrix() {
        _size = 10;
        _vec_size = 10;
        _vectors = new Vector<T>[_size];
    }

    Matrix(size_t size) {
        _size = size;
        _vec_size = _size;
        _vectors = new Vector<T>[_size];
    }

    Matrix(size_t size, size_t vec_size) {
        _size = size;
        _vec_size = vec_size;
        _vectors = new Vector<T>[_size];
        for (size_t i = 0; i < _size; i++) _vectors[i] = Vector<T>(_vec_size);
    }

    Matrix(size_t size, size_t vec_size, Vector<T> *vectors) {
        _size = size;
        _vec_size = vec_size;
        _vectors = new Vector<T>[_size];
        for (size_t i = 0; i < size; i++) _vectors[i] = vectors[i];
    }

    Vector<T> &operator[](int index) const {
        return _vectors[index];
    }

    ~Matrix() {
        delete[] _vectors;
    }

//    void SetSize(size_t x){_size = x;
//        return;}
//    void SetVecSize(size_t x){_vec_size = x;
//        return;}


    Matrix Transposition() {
        Matrix res = Matrix(_vec_size, _size);
        for (size_t i = 0; i < _vec_size; i++) {
            for (size_t j = 0; j < _size; j++) {
                res._vectors[i][j] = _vectors[j][i];
            }
        }
        return res;
    }

    Matrix operator+(const Matrix &m) const {
        if (_size != m._size) {
            throw "Invalid matrix size!";
        }
        Matrix n = Matrix(m._size);
        for (size_t i = 0; i < _size; i++) {
            n[i] = (*this)[i] + m[i];
        }
        return n;
    }

    Matrix operator-(const Matrix &m) const {
        if (_size != m._size) {
            throw "Invalid matrix size!";
        }
        Matrix n = Matrix(m._size);
        for (size_t i = 0; i < _size; i++) {
            n[i] = (*this)[i] - m[i];
        }
        return n;
    }

    Matrix operator*(const Matrix &m) const {
        if (_vec_size != m._size) {
            throw "Invalid matrix size!";
        }

        Matrix n = Matrix(_size, m._vec_size);
        T sum = 0;
        for (size_t i = 0; i < _size; i++) {
            for (size_t t = 0; t < m._vec_size; t++) {
                sum = 0;
                for (size_t j = 0; j < _vec_size; j++) {
                    sum += _vectors[i][j] * m._vectors[j][t];
                }
                n[i][t] = sum;
//                    std::cout << n;
            }
        }
//            n._size = _size;
//            n._vec_size =_vec_size;
        return n;
    }

    T determinantNxN(Matrix sub) {
        if (sub._size != sub._vec_size) { throw "No Determinant ;)"; }
        if (sub._size == 1) return sub._vectors[0][0];
        if (sub._size == 2) {
            return sub._vectors[0][0] * sub._vectors[1][1] - sub._vectors[0][1] * sub._vectors[1][0];
        } else if (_size == 3) {
            return sub._vectors[0][0] * (sub._vectors[1][1] * sub._vectors[2][2] - sub._vectors[1][2] * sub._vectors[2][1]) -
                    sub._vectors[0][1] * (sub._vectors[1][0] * sub._vectors[2][2] - sub._vectors[1][2] * sub._vectors[2][0]) +
                    sub._vectors[0][2] * (sub._vectors[1][0] * sub._vectors[2][1] - sub._vectors[1][1] * sub._vectors[2][0]);
        } else {
            T det = 0;
            for (size_t i = 0; i < sub._size; ++i) {
                Matrix<T> submatrix = Matrix<T>(size_t (sub._size - 1));
                size_t index = 0;
                for (size_t j = sub._size; j < sub._size * sub._size; ++j) {
                    if (j % sub._size != i) {
                        submatrix[index++] = sub._vectors[j / sub._size][j % sub._size];
                    }
                }
                det += (i % 2 == 0 ? 1 : -1) * sub._vectors[i / sub._size][i % sub._size] * determinantNxN(submatrix);
            }
            return det;
        }
    }


    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        for (size_t i = 0; i < matrix._size; i++)
            os << matrix._vectors[i];
        os << std::endl;
        return os;
    }


};