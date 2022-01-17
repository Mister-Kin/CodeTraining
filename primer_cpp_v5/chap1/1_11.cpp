#include <iostream>

int main()
{
    int num1, num2;
    std::cout << "Please input two integers:" << std::endl;
    std::cin >> num1 >> num2;

    if (num1 <= num2)
    {
        while (num1 <= num2)
        {
            std::cout << num1 << std::endl;
            num1++;
        }
    }
    else
    {
        while (num2 <= num1)
        {
            std::cout << num2 << std::endl;
            num2++;
        }
    }

    return 0;
}
