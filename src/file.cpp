#include "../include/file.h"

void save(const set_t &array, const std::string &filename)
{
    std::ofstream fs(filename);
    fs << array.size() << std::endl;
    for (auto &elem : array)
    {
        elem -> save(fs);
    }
    fs.flush();
    fs.close();
}

set_t load(const std::string &filename)
{
    set_t result;
    std::ifstream is(filename);

    if (is.good() && is.is_open())
    {
        int count;
        is >> count;

        Factory factor;

        for (int i = 0; i < count; ++i)
        {
            result.insert(factor.factory(is));
        }

        is.close();
    }

    else
    {
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
    }

    return result;
}