#include <iostream>

int larger_num(int num1, const int *num2)
{
    return (num1 > *num2) ? num1 : *num2;
}

int main(int argc, char const *argv[])
{
    int num1 = 10, num2 = 20;
    std::cout << larger_num(num1, &num2) << std::endl;
    return 0;
}
