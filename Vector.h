#pragma once
#include <iostream>

template<typename T>
class Vector{
private:
    T* _array;
    size_t _size;
public:
    Vector(){
        _size = 10;
        _array = new T[_size];
        for (size_t i=0; i < _size; i++)
            _array[i] = 0;
    }


    Vector(std::initializer_list<T> list){
        _size = list.size();
        size_t i=0;
        _array = new T[_size];
        for (auto elem = list.begin();
             elem != list.end(); elem++){
            _array[i] = *elem;
            i++;
        }

    }

    Vector(size_t size) : _size(size){
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = 0;
    }


    Vector(size_t size, T* array) : _size(size),
                                    _array(new T[size])
    {
        for (size_t i=0; i < _size; i++)
            _array[i] = array[i];
    }

    Vector(const Vector& tmp){
        _size = tmp._size;
        _array = new T[tmp._size];
        for (size_t i=0; i < _size; i++)
            _array[i] = tmp._array[i];
    }

    Vector& operator=(const Vector& tmp){
        if (this == &tmp)
            return *this;
        if (tmp._size != _size){
            delete [] _array;
            _size = tmp._size;
            _array = new T[_size];
        }
        for (size_t i = 0; i < _size; i++)
            _array[i] = tmp._array[i];
        return *this;
    }

    ~Vector(){
        delete [] _array;
    }

    const T& operator[](int index) const{
            if(index < 0 || index >= _size) {
                throw "Index out of range";
            }
            return _array[index];
    }

    T& operator[](int index) {
            if(index < 0 || index >= _size) {
                throw "Index out of range";
            }
            return _array[index];
    }

    Vector operator+(const Vector& tmp) const {
        if (_size != tmp._size)
        {
            throw "Invalid vector size!";
        }
        Vector v = Vector(tmp._size);
        for (size_t i = 0; i < _size; i++)
        {
            v[i] = tmp[i] + (*this)[i];
        }
        return v;
    }

    Vector operator-(const Vector& tmp) const {
        if (_size != tmp._size)
        {
            throw "Invalid vector size!";
        }
        Vector v = Vector(tmp._size);
        for (size_t i = 0; i < _size; i++)
        {
            v[i] = (*this)[i] - tmp[i] ;
        }
        return v;
    }

    Vector operator*(const Vector& tmp) const {
        if (_size != tmp._size)
        {
            throw "Invalid vector size!";
        }
        Vector v = Vector(tmp._size);
        for (size_t i = 0; i < _size; i++)
        {
            v[i] = (*this)[i] * tmp[i] ;
        }
        return v;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec){
        os << "(";
        for (size_t i = 0; i < vec._size; i++){
            os << vec._array[i];
            if (i + 1 != vec._size)
                os << ", ";
        }
        os << ")" << std::endl;
        return os;
    }
};