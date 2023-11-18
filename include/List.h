#pragma once
#include <iostream>
#include <iterator>
#include <memory>

template <class T, typename Alloc = std::allocator<T>>
class List
{
    private:
        struct ListItem
        {
            std::unique_ptr<ListItem> next;
            T value;

            void push_back(T &value)
            {
                if (next)
                {
                    next -> push_back(value);
                }
                else
                {
                    next = std::make_unique<ListItem>(ListItem {std::unique_ptr<ListItem>(), value});
                }
            }

            T& get(size_t index)
            {
                if (index == 0) 
                {
                    return value;
                }

                if (next)
                {
                    return next -> get(--index);
                }
                throw std::logic_error("Out of range");
            }

            void insert(ListItem &prev, size_t index, const T& value)
            {
                if (index == 0)
                {
                    prev.next = std::make_unique<ListItem>(ListItem{std::move(prev.next), value});
                    return;
                }

                if (next)
                {
                    return next -> insert(*this, --index, value);
                }
                throw std::logic_error("Out of range");
            }

            void erase(ListItem &prev, size_t index)
            {
                if (index == 0)
                {
                    prev.next = std::move(next);
                    return;
                }

                if (next)
                {
                    return next -> erase(*this, --index);
                }
                
                throw std::logic_error("Out of range");
            }

            size_t size()
            {
                if (next)
                {
                    return next -> size() + 1;
                }
                return 1;
            }
        };

    std::unique_ptr<ListItem> head;
    public:
        using value_type = T;
        using allocator_type = Alloc;
        using pointer = typename std::allocator_traits<Alloc>::pointer;
        using size_type = std::size_t;
        //typename Alloc::template rebind<ListItem>::other _node_allocator;
        class ListIterator
        {
            private:
                List& list;
                size_t index;
                friend class List;
            public:
                using difference_type = int;
                using value_type = List::value_type;
                using reference = List::value_type&;
                using pointer = List::value_type*;
                using iterator_category = std::forward_iterator_tag;

                ListIterator(List &l, int i) : list(l), index(i) {}

                ListIterator& operator++()
                {
                    ++index;
                    return *this;
                }

                reference operator*()
                {
                    return list[index];
                }

                pointer operator-> ()
                {
                    return &list[index];
                }

                bool operator != (const ListIterator &other) const
                {
                    if (index != other.index)
                    {
                        return true;
                    }

                    if (&list != &(other.list))
                    {
                        return true;
                    }

                    return false;
                }

                bool operator== (const ListIterator &other)const
                {
                    if (index != other.index)
                    {
                        return false;
                    }

                    if (&list != &(other.list))
                    {
                        return false;
                    }

                    return true;
                }
        };

        class ConstIterator
        {
            private:
                List& list;
                size_t index;
                friend class List;
            public:
                using difference_type = int;
                using value_type = List::value_type;
                using reference = const List::value_type&;
                using pointer = const List::value_type*;
                using iterator_category = std::forward_iterator_tag;

                ConstIterator() = default;
                ConstIterator(List &l, int i) : list(l), index(i) {}

                ConstIterator& operator++()
                {
                    ++index;
                    return *this;
                }

                reference operator*()
                {
                    return list[index];
                }

                pointer operator-> ()
                {
                    return &list[index];
                }

                bool operator != (const ConstIterator &other) const
                {
                    if (index != other.index)
                    {
                        return true;
                    }

                    if (&list != &(other.list))
                    {
                        return true;
                    }

                    return false;
                }

                bool operator== (const ConstIterator &other)const
                {
                    if (index != other.index)
                    {
                        return false;
                    }

                    if (&list != &(other.list))
                    {
                        return false;
                    }

                    return true;
                }
        };

        void push_back(T& value)
        {
            if (head)
            {
                head -> push_back(value);
            }
            else
            {
                head = std::make_unique<ListItem>(ListItem {std::unique_ptr<ListItem>(), value});
            }
        }

        size_t size()
        {
            if (!head)
            {
                return 0;
            }

            return head -> size();
        }

        T& operator[] (size_t index)
        {
            if (!head)
            {
                throw std::logic_error("Out of range");
            }

            return head -> get(index);
        }

        ListIterator erase(ListIterator iter)
        {
            if (iter.index == 0)
            {
                head = std::move(head -> next);
            }
            else
            {
                if (head -> next)
                {
                    head -> next -> erase(*head, iter.index - 1);
                }
            }

            if (iter.index < size())
            {
                return iter;
            }

            return ListIterator(*this, size());
        }

        ListIterator insert (ListIterator iter, const T &value)
        {
            if (iter.index == 0)
            {
                head = std::make_unique<ListItem> (ListItem {std::move(head), value});
            }
            else
            {
                if (head -> next)
                {
                    head -> next -> insert(*head, iter.index - 1, value);
                }
            }

            if(iter.index < size())
            {
                return iter;
            }

            return ListIterator(*this, size());
        }

        T front()
        {
            T element = head -> get(0);
            return element;
        }

        T back()
        {
            T element = head -> get(size() - 1);
            return element;
        }

        bool empty()
        {
            return (size() == 0); //return size() is also possible
        }

        ListIterator begin()
        {
            return ListIterator(*this, 0);
        }

        ListIterator end()
        {
            return ListIterator(*this, size());
        }

        ConstIterator cbegin()
        {
            return ConstIterator(*this, 0);
        }

        ConstIterator cend()
        {
            return ConstIterator(*this, size());
        }

        ~List() = default;
};
