#include <iostream>
#include <array>
#include "easyfind.hpp"

int main()
{
    std::array<int, 5> numbers = {1, 2, 3, 4, 5};

    try {
        std::array<int, 5>::iterator result = easyfind(numbers, 3);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Not found" << std::endl;
    }

    try {
        std::array<int, 5>::iterator result = easyfind(numbers, 6);
        std::cout << "Found: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}