#pragma once
#include "Vector.h"

template<typename T>
class Matrix{
private:
    size_t _size;
    Vector<T>* _vectors;
    size_t _vec_size;
public:
    Matrix(){
        _size = 10;
        _vec_size = 10;
        _vectors = new Vector<T>[_size];
    }
    Matrix(size_t size){
        _size = size;
        _vec_size = 10;
        _vectors = new Vector<T>[_size];
    }

    Matrix(size_t size, size_t vec_size){
        _size = size;
        _vec_size = vec_size;
        _vectors = new Vector<T>[_size];
        for (size_t i = 0; i < _size; i++) _vectors[i] = Vector<T>(_vec_size);
    }

    Matrix(size_t size, size_t vec_size, Vector<T>* vectors){
        _size = size;
        _vec_size = vec_size;
        _vectors = new Vector<T>[_size];
        for (size_t i = 0; i < size; i++) _vectors[i] = vectors[i];
    }

    Vector<T>& operator[](int index) const{
        return _vectors[index];
    }

    ~Matrix(){
        delete [] _vectors;
    }

    Matrix Transposition(){
        Matrix res = Matrix(_vec_size, _size);
        for (size_t i = 0; i < _vec_size; i++){
            for (size_t j = 0; j < _size; j++){
                res._vectors[i][j] = _vectors[_size - 1 - j][i];
            }
        }
        return res;
    }

    Matrix operator+(const Matrix& m)const{
        if (_size != m._size)
        {
            throw "Invalid matrix size!";
        }
        Matrix n = Matrix(m._size);
        for (size_t i = 0; i < _size; i++)
        {
            n[i] = (*this)[i] + m[i];
        }
        return n;
    }

    Matrix operator-(const Matrix& m)const{
        if (_size != m._size)
        {
            throw "Invalid matrix size!";
        }
        Matrix n = Matrix(m._size);
        for (size_t i = 0; i < _size; i++)
        {
            n[i] = (*this)[i] - m[i];
        }
        return n;
    }

    Matrix operator*(const Matrix& m) const {
        if (_vec_size != m._size) {
            throw "Invalid matrix size!";
        }
        else {
            Matrix n = Matrix(_size, m._vec_size);

            T sum = 0;
            for (size_t i = 0; i < _size; i++) {
                for (size_t t = 0; t < m._vec_size; t++) {
                    sum = 0;
                    for (size_t j = 0; j < _vec_size; j++) {
                        sum += _vectors[i][j] * m._vectors[j][t];
                    }
                    n[i][t] = sum;
                    std::cout << n;
                }
            }
            return n;
        }
    }




    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
        for (size_t i =0; i < matrix._size; i++)
            os << matrix._vectors[i];
        os << std::endl;
        return os;
    }



};