/*
DArray.h

Dynamic array data structure
*/

#ifndef DARRAY_H
#define DARRAY_H

#include <algorithm>
#include <utility>
#include <iostream>
#include <cstddef>

// These forward declarations are required for operator<<() to work,
// no idea why

template <class T>
class DArray;

template <class T>
std::ostream& operator<<(std::ostream& output, const DArray<T>& arr);

template <class T>
class DArray
{
    public:

        explicit DArray(std::size_t init_size = 0);
        ~DArray();

        DArray(const DArray& source);
        DArray& operator=(const DArray& source);

        DArray(DArray&& source);
        DArray& operator=(DArray&& source);

        void resize(std::size_t new_size);
        void reserve(std::size_t new_capacity);

        T& operator[](std::size_t index) { return arr[index]; }
        const T& operator[](std::size_t index) const { return arr[index]; }

        bool empty() const { return size() == 0; }
        std::size_t size() const { return sz; }
        std::size_t capacity() const { return cap; }

        void push_back(const T& x);
        void push_back(T&& x);

        void pop_back() { --sz; }
        const T& back() const { return arr[sz - 1]; }

        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin() { return &arr[0]; }
        const_iterator begin() const { return &arr[0]; }

        iterator end() { return &arr[sz]; }
        const_iterator end() const { return &arr[sz]; }

        static const std::size_t SPARE_CAPACITY = 16;

    private:

        std::size_t sz;
        std::size_t cap;
        T* arr;

        friend std::ostream& operator<<<T>(
            std::ostream& output, const DArray& arr);
};

template <class T>
DArray<T>::DArray(std::size_t init_size)
    : sz{ init_size }, cap{ init_size + SPARE_CAPACITY }
{
    arr = new T[cap];
}

template <class T>
DArray<T>::~DArray()
{
    delete[] arr;
}

template <class T>
DArray<T>::DArray(const DArray& source)
    : sz{ source.sz }, cap{ source.cap }, arr{ nullptr }
{
    arr = new T[cap];
    for (std::size_t i = 0; i < sz; ++i)
        arr[i] = source.arr[i];
}

template <class T>
DArray<T>& DArray<T>::operator=(const DArray& source)
{
    DArray copy = source;
    std::swap(*this, copy);
    return *this;
}

template <class T>
DArray<T>::DArray(DArray&& source)
    : sz{ source.sz }, cap{ source.cap }, arr{ source.arr }
{
    source.sz = 0;
    source.cap = 0;
    source.arr = nullptr;
}

template <class T>
DArray<T>& DArray<T>::operator=(DArray&& source)
{
    std::swap(sz, source.sz);
    std::swap(cap, source.cap);
    std::swap(arr, source.arr);
}

template <class T>
void DArray<T>::resize(std::size_t new_size)
{
    if (new_size > cap) reserve(new_size * 2 + 1);  // In case size = 0
    sz = new_size;
}

template <class T>
void DArray<T>::reserve(std::size_t new_capacity)
{
    if (new_capacity < sz) return;  // Can not allow this

    T* new_arr = new T[new_capacity];
    for (std::size_t i = 0; i < sz; ++i) new_arr[i] = std::move(arr[i]);

    cap = new_capacity;
    std::swap(arr, new_arr);
    delete[] new_arr;
}

template <class T>
void DArray<T>::push_back(const T& x)
{
    if (sz == cap) reserve(sz * 2 + 1);
    arr[sz++] = x;
}

template <class T>
void DArray<T>::push_back(T&& x)
{
    if (sz == cap) reserve(sz * 2 + 1);
    arr[sz++] = std::move(x);
}

template <class T>
std::ostream& operator<<(std::ostream& output, const DArray<T>& arr)
{
    if (arr.empty())
    {
        output << "[]";
        return output;
    }

    output << '[';
    for (typename DArray<T>::const_iterator itr = arr.begin();
            itr != arr.end(); ++itr)
    {
        if (itr == arr.end()-1) output << *itr << ']';
        else output << *itr << ", ";
    }

    return output;
}

#endif  // DARRAY_H