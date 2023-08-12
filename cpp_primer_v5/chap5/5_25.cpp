#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    int i, j;
    std::cout << std::format("Enter two numbers: ");
    while (std::cin >> i >> j)
    {
        try
        {
            if (j == 0)
                throw std::runtime_error("Cannot divide by zero");
            std::cout << std::format("The quotient of {} and {} is: {}\n", i, j, i / j) << std::endl;
        }
        catch (std::runtime_error err)
        {
            std::cerr << err.what() << "\nTry Again? Enter y or n" << std::endl;
            char c;
            std::cin >> c;
            if (c == 'n')
                break;
        }
        std::cout << std::format("Enter two numbers: ");
    }

    return 0;
}
