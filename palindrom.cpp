#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "palindrom.h"

bool negative_number(std::string& str)
{
    bool flag = false;
    for (int index = 0; index < str.size(); ++index)
    {
        if (str[index] == '-' && flag == false)
        {
            flag = true;
        }
        else
        {
            if (isdigit(str[index]))
            {
                continue;
            }
            if (isalpha(str[index]))
            {
                flag = false;
                continue;
            }
            else
            {
                return true;
            }
        }
    }
    return flag;
}

void to_lowercase(std::string& str)
{
    for (int index = 0; index < str.size(); ++index)
    {
        str[index] = std::tolower(str[index]);
    }
}

void delete_spaces(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());
}

void delete_separators(std::string& str)
{
    str.erase(std::remove_if(str.begin(), str.end(), ispunct), str.end());
}

bool ispalindrom(std::string str)
{
    delete_spaces(str);
    if (negative_number(str))
    {
        return false;
    }

    delete_separators(str);
    
    to_lowercase(str);
    
    for (int index = 0; index < str.size(); ++index)
    {
        if (str[index] != str[str.size() - index - 1])
        {
            return false;
            break;
        }
    }
    return true;
}