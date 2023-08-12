#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    int i, j;
    std::cout << std::format("Enter two numbers: ");
    std::cin >> i >> j;
    if (j == 0)
        throw std::runtime_error("Cannot divide by zero");
    std::cout << std::format("The quotient of {} and {} is: {}\n", i, j, i / j) << std::endl;

    return 0;
}
