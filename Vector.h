//
// Created by 11ale on 07.04.2024.
//

#ifndef LABA_5_MATRIX_VECTOR_H
#define LABA_5_MATRIX_VECTOR_H

#endif //LABA_5_MATRIX_VECTOR_H
#pragma once
#include <cmath>
#include <iostream>
//перегрузить оператор + - *(скалярное произведение). Длина вектора. Нормализация вектора. Конструкторы копирования и присваивания(подумать не делать).
template<typename T>
class Vector
{
private:
    T* _array;
    size_t _size;
public:
    Vector(){
        _size = 10;
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    };

    Vector(size_t size) : _size(size){
        _array = new T[_size];
        for (int i = 0; i < _size; i++){
            _array[i] = 0;
        }
    }

    Vector(std::initializer_list<T> list){
        _size = list.size();
        _array = new T[_size];
        int i = 0;
        for (auto elem = list.begin(); elem != list.end(); ++elem){
            _array[i] = *elem;
            i++;
        }
    }

    Vector(size_t size, T* array) : _size(size), _array(new T[size]){
        for (int i = 0; i < _size; i++){
            _array[i] = array[i];
        }
    }

    ~Vector(){
        delete [] _array;
    }

    Vector operator+(const Vector& vec) const{
        if (_size != vec._size) throw "Error";
        T* array = new T[vec._size];
        for (int i = 0; i < _size; i++){
            array[i] = _array[i] + vec._array[i];
        }
        auto v = Vector(_size, array);
        delete [] array;
        return v;
    }

    Vector operator-(const Vector& vec) const{
        if (_size != vec._size) throw "Error";
        T* array = new T[vec._size];
        for (int i = 0; i < _size; i++){
            array[i] = _array[i] - vec._array[i];
        }
        auto v = Vector(_size, array);
        delete [] array;
        return v;
    }

    T scalarMultiply(Vector& vec2){
        if (_size != vec2._size) return 0;
        T res = 0;
        for (int i = 0; i < _size; i++){
            res += _array[i] * vec2._array[i];
        }
        // delete [] vec2._array;
        return res;
    }

    double findLength(){
        double length = 0;
        for (int i = 0; i < _size; i++){
            length += _array[i] * _array[i];
        }
        length = pow(length, 0.5);
        return length;
    }

    Vector<double> normalization(){
        double* array = new double[_size];
        size_t size = _size;
        for (int i = 0; i < _size; i++){
            array[i] = static_cast<double>(_array[i]) / this->findLength();
        }
        auto v = Vector<double>(_size, array);
        delete [] array;
        return v;
    }

    const T& operator[](int index) const{
        return _array[index];
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector& tmp){
        os << "(";
        for (int i = 0; i < tmp._size; i++){
            os << tmp._array[i];
            if (i + 1 != tmp._size) os << ", ";
        }
        os << ")" << std::endl;
        return os;
    }

};