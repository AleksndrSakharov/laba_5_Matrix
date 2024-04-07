//
// Created by 11ale on 07.04.2024.
//
#pragma once
#include "Vector.h"
#ifndef LABA_5_MATRIX_MATRIX_H
#define LABA_5_MATRIX_MATRIX_H

#endif //LABA_5_MATRIX_MATRIX_H

template<typename T>
class Matrix{
private:
    size_t _size;
    Vector<T>** _vectors;
public:
    Matrix(){
        _size = 10;
        _vectors = new Vector<T>[_size];
        int s = 0 ;
        for (size_t i = 0; i < _size; i ++)
            _vectors[i] = new Vector<T>();
    }

    ~Matrix(){
        // for (size_t i = 0 ; i < _size ; i ++ ){
        //     delete _vectors[i];
        // }
        delete [] _vectors;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
        for(size_t i = 0 ; i < matrix._size; i ++ ){
            os << matrix._vectors[i];
        }
        return os;
    }
};
