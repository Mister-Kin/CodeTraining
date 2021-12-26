// 输入两个整数，打印这两个整数所指定范围内的所有整数。

#include <iostream>

int main(int argc, char const *argv[])
{
    int num1, num2;
    std::cout << "Please Input Two Integers:" << std::endl;
    std::cin >> num1 >> num2;

    while (num2 <= num1)
    {
        std::cout << num2 << std::endl;
        num2++;
    }

    return 0;
}
