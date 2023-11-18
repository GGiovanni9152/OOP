#pragma once
#include <iostream>
#include <array>
#include <map>
#include <vector>
#include <chrono>
#include <list>

namespace mai
{
    template <class T>  //, size_t BLOCK_SIZE
    class Allocator
    {
        private:
            static constexpr size_t max_count = 100000;
            char* _used_blocks;
            std::array<void*, max_count> _free_blocks;
            uint64_t _free_count;

        public:
            using value_type = T;
            using pointer = T*;
            using const_pointer = const T*;
            using size_type = std::size_t;

            Allocator()
            {
                _used_blocks = (char*) malloc(sizeof(T) * max_count);
                //T* first_elem = _used_blocks;
                for (uint64_t i = 0; i < max_count; i++)
                {
                    _free_blocks[i] = _used_blocks + i * sizeof(T); //_used_blocks
                }
                _free_count = max_count;
            }

            ~Allocator()
            {
                delete _used_blocks;
                _used_blocks = nullptr;
            }

            template <class U>
            struct rebind
            {
                using other = Allocator<U>;
            };

            T* allocate(size_t n)
            {
                T* result = nullptr;

                if (_free_count > 0)
                {
                    result = (T*) _free_blocks[--_free_count];
                }

                else
                {
                    std::cout << "allocator: No memory exception" << std::endl;
                }

                return result;
            }

            void deallocate(T* pointer, size_t)
            {
                _free_blocks[_free_count++] = pointer;
            }

            template <typename U, typename... Args>
            void construct(U *p, Args &&...args)
            {
                new (p) U(std::forward<Args>(args)...);
            }

            void destroy(pointer p)
            {
                p -> ~T();
            }
    }; 
    
    template <class T, class U>
    constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) 
    {
        return true;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)  
    {
        return false;
    }

}
