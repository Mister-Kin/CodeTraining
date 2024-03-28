#include <iostream>

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

int fact2(int i)
{
    int result = 1;
    while (i)
    {
        result *= i--;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::cout << fact(5) << std::endl;
    std::cout << fact2(5) << std::endl;
    return 0;
}
