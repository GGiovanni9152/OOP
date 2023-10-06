#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Four
{
    public:
        Four();
        Four(const int &input_size, unsigned char input_char);
        Four(const std::initializer_list <unsigned char> &list);
        Four(const std::string &input_string);
        Four(const Four &other);
        Four(Four &&other) noexcept;
        
        Four& operator= (const Four &other);
        Four operator+ (const Four &other);
        Four& operator+= (const Four &other);
        Four operator- (const Four &other);
        Four operator-= (const Four &other);
        bool operator== (const Four &other);
        bool operator> (const Four &other);
        bool operator< (const Four &other);
        
        friend std::istream& operator>>(std::istream &is, Four &four);
        std::ostream& print(std::ostream &os);
        bool save_to_file(const std::string &filename);
        bool read_from_file(const std::string &filename);
        
        virtual ~Four() noexcept;
        
    
    private:
        int _size;
        unsigned char *_array;
        Four(const int &input_size, const unsigned char* input_array);
        void shrink();
        void belongs_to_Four(const unsigned char &symbol);
};
