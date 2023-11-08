#pragma once
#include <iostream>
#include <concepts>
#include <memory>
#include <assert.h>
#include "Point.h"

template <class T>
concept Arrayable = std::is_default_constructible<T>::value;

template <Arrayable T>
class Array
{
    public:
        Array(): _size(0), _array{nullptr} {};
    
        Array(const std::initializer_list<T> &t)
        {
            _array = std::shared_ptr<T[]> (new T[t.size()]);
            size_t i{0};
            for (auto &c : t)
            {
                _array[i++] = c;
            }
            _size = t.size();
        }

        Array(const Array &other)
        {
            _size = other._size;
            _array = std::shared_ptr<T[]> (new T[_size]);

            for (int i = 0; i < _size; ++i)
            {
                _array[i] = other._array[i];
            }
        }

        Array(Array &&other) noexcept
        {
            _size = other._size;
            _array = other._array;

            other._size = 0;
            other._array = nullptr;
        }

        T& operator[](int index)
        {
            assert(index < _size);
            return _array[index];
        }

        int size() const
        {
            return _size;
        }

        double total_area()  //Think about double
        {
            double summa;
            
            for (int i = 0; i < _size; ++i)
            {
                summa += _array[i] -> area();
            }

            return summa;
        }

        void print()
        {
            for (int i = 0; i < _size; ++i)
            {
                std::cout << *(_array[i]) << '\n';
            }
        }

        double element_area(int index)
        {
            return _array[index] -> area();
        }

        Point <double> element_center(int index)
        {
            return _array[index] -> center();
        }

        void print_centers()
        {
            for (int i = 0; i < _size; ++i)
            {
                std::cout << _array[i] -> center() << '\n';
            }
        }

        void remove_element(int index)
        {
            std::shared_ptr<T[]> new_array;
            new_array = std::shared_ptr<T[]> (new T[_size - 1]);
            
            for (int i = 0; i < index; ++i)
            {
                new_array[i] = _array[i];
            }

            for (int i = index; i < _size - 1; ++i)
            {
                new_array[i] = _array[i + 1];
            }

            //delete _array;
            _array = new_array;
            --_size;
        }

    private:
        int _size;
        std::shared_ptr<T[]> _array;
};