#include <iostream>

int main()
{
    // 练习1.9
    int sum = 0;
    for (int i = 50; i <= 100; i++)
        sum += i;
    std::cout << "The sum of 50 to 100 is "
              << sum << std::endl;

    // 练习1.10
    for (int i = 10; i >= 0; i--)
        std::cout << i << std::endl;

    // 练习1.11
    std::cout << "Please input two integer: ";
    int num1, num2;
    std::cin >> num1 >> num2;
    if (num1 > num2)
    {
        for (; num2 <= num1; num2++)
            std::cout << num2 << std::endl;
    }
    else
    {
        for (; num1 <= num2; num1++)
            std::cout << num1 << std::endl;
    }

    return 0;
}
