#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "palindrom.h"

int main()
{
    std::cout << "Enter your string to check" << std::endl;

    std::string input_string; 
    std::getline(std::cin, input_string);

    if (ispalindrom(input_string)){
        std::cout << "It's a palindrom!";
    }
    else{
        std::cout << "It's not a palindrom :("; 
    }
    
    return 0;
}
