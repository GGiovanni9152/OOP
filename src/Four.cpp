#include <iostream>
#include "../include/Four.h"


Four::Four(): _size(0), _array{nullptr} {}; //default const;

Four::Four(const int &input_size, unsigned char input_char) //Fill constructor
{
    _array = new unsigned char[input_size];
    _size = input_size;
    for (int index = 0; index < _size; ++index)
    {
        belongs_to_Four(input_char);
        _array[index] = input_char;
    }
}


Four::Four(const std::initializer_list <unsigned char> &list) //initializer_list construct
{
    _array = new unsigned char[list.size()];
    int index = list.size() - 1;
    
    for (unsigned char element : list)
    {
        belongs_to_Four(element);
        _array[index--] = element;
    }
    
    _size = list.size();
}


Four::Four(const std::string &input_string) 
{
    _size = input_string.size();
    _array = new unsigned char[_size];
    
    for (int index = 0; index < _size; ++index)
    {
        belongs_to_Four(input_string[_size - index - 1]);
        _array[index] = input_string[_size - index - 1];
    }
}

Four::Four(const Four &other)
{
    _size = other._size;
    _array = new unsigned char[_size];
    
    for (int index = 0; index < _size; ++index)
    {
        _array[index] = other._array[index];
    }
}

Four::Four(Four &&other) noexcept 
{
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}


Four& Four::operator= (const Four &other)
{
    _size = other._size;
    _array = new unsigned char[_size];
    
    for (int index = 0; index < _size; ++index)
    {
        _array[index] = other._array[index];
    }
    
    return *this;
}

Four Four::operator+ (const Four &other)
{
    unsigned char* new_array;
    int new_size = std::max(_size, other._size) + 1;
    int minimal_size = std::min(_size, other._size);

    new_array = new unsigned char[new_size];
    int carry = 0;
        
    for (int index = 0; index < minimal_size; ++index)
    {
        int summa = (_array[index] - '0') + (other._array[index] - '0') + carry;
        carry = summa / 4;
        char symbol = (summa % 4 + '0'); 
        new_array[index] = symbol;
    }
        
    for (int index = minimal_size; index < new_size - 1; ++index)
    {
        int summa =  (other._array[index] - '0') + carry;
        carry = summa / 4;
        char symbol = (summa % 4 + '0'); 
        new_array[index] = symbol;
    }
       
    new_array[new_size - 1] = '0' + carry;
    
    
    Four new_four(new_size, new_array);
    new_four.shrink();
    
    return new_four;
}

Four& Four::operator+= (const Four &other)
{
    Four new_four = *this + other;
    *this = new_four;
    return *this;
}

Four Four::operator- (const Four &other)
{
    if (_size < other._size) 
    {
        throw std::logic_error("Four operates only with positive numbers");
    }
        
    int carry = 0;
    int maximum_size = std::max(_size, other._size);
    int minimum_size = std::min(_size, other._size);
    unsigned char* new_array = new unsigned char[maximum_size];
        
    for (int index = 0; index < minimum_size; ++index)
    {
        int first_num = _array[index] - '0';
        int second_num = other._array[index] - '0';
        int summa = first_num - second_num + carry;
            
        if (summa < 0)
        {
            carry = -1;
            summa = (4 + summa) % 4;
        }
        else
        {
            carry = 0;
        }
            
        new_array[index] = summa + '0';
    }
        
    for (int index = minimum_size; index < maximum_size; ++index)
    {
        int num = _array[index] - '0';
        int summa = num + carry;
            
        if (summa < 0)
        {
            carry = -1;
            summa = (4 + summa) % 4;
        }
        else
        {
            carry = 0;
        }
            
        new_array[index] = summa + '0';
    }
        
    if (carry < 0)
    {
        throw std::underflow_error("Four operates only with positive numbers");
    }
        
    Four new_four(_size, new_array);    
    new_four.shrink();
    return new_four;
}

Four Four::operator-= (const Four &other)
{
    Four new_four = *this - other;
    *this = new_four;
    return *this;
}

bool Four::operator== (const Four &other)
{
    if (_size != other._size)
    {
        return false;
    }
    else
    {
        for (int index = 0; index < _size; ++index)
        {
            char first_num = _array[index];
            char second_num = other._array[index];
            
            if (first_num != second_num)
            {
                return false;
            }
        }
    }
    
    return true;
}

bool Four::operator> (const Four &other)
{
    if (_size > other._size)
    {
        return true;
    }
    
    if (_size < other._size)
    {
        return false;
    }
    else
    {
        for (int index = _size - 1; index >= 0; --index)
        {
            int first_num = _array[index];
            int second_num = other._array[index];
            
            if (first_num > second_num)
            {
                return true;
            }
            
            if (first_num < second_num)
            {
                return false;
            }
        }
    }
    
    return false;
}

bool Four::operator< (const Four &other)
{
    return (!(*this > other) && !(*this == other));
}


std::ostream& Four::print(std::ostream &os)
{
    for (int index = _size - 1; index >= 0; --index)
    {
        os << _array[index]; 
    }
    return os;
}

std::istream& operator>>(std::istream &is, Four &four)
{
    std::string input_string;
    is >> input_string;
    Four temporary_four(input_string);
    four = temporary_four;
    return is;
    
}

bool Four::save_to_file(const std::string &filename)
{
    std::ofstream output_file(filename, std::ios::out);
    
    if(!output_file)
    {
        return false;
    }
    
    for (int index = _size - 1; index >= 0; --index)
    {
        output_file << _array[index];
    }
    
    output_file << '\n';
    
    output_file.close();
    
    return true;
}

bool Four::read_from_file(const std::string &filename)
{
    std::ifstream input_file(filename, std::ios::in);
    
    if (!input_file)
    {
        return false;
    }
    
    std::string input_string;
    input_file >> input_string;
    _size = input_string.size();
    
    if(_size > 0)
    {
        delete []_array;
    }
    
    _array = new unsigned char[_size];
    
    for (int index = _size - 1; index >= 0; --index)
    {
        _array[index] = input_string[_size - index - 1];
    }
    
    input_file.close();
    
    return true;
}

Four::~Four() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

Four::Four(const int &input_size, const unsigned char* input_array)
{
    _size = input_size;
    _array = new unsigned char[_size];
    int index = 0;
    
    for (int index = 0; index < _size; ++index)
    {
        _array[index] = input_array[index];  
    }
}

void Four::shrink()
{
    int new_size = _size - 1;
    for (int index = _size - 1; index >= 0; --index)
    {
        if (_array[index] != '0')
        {
            new_size = index + 1;
            break;
        }
        new_size = index + 1;
    }
    
    if (new_size == 0)
    {
        delete[] _array;
        _array = new unsigned char[1];
        _size = 1;
        return;
    }
    
    unsigned char* new_array = new unsigned char[new_size];
    
    for (int index = 0; index < new_size; ++index)
    {
        new_array[index] = _array[index];
    }
    
    delete[] _array;
    _array = new_array;
    _size = new_size;
    return;
}

void Four::belongs_to_Four(const unsigned char &symbol)
{
    if ((symbol > '3') || (symbol < '0')) 
    {
        throw std::invalid_argument("Only 0,1,2,3 are available!");
    }
}