// 输入两个整数，打印这两个整数所指定范围内的所有整数，程序能够处理用户输入第一个数比第二个数小的情况。

#include <iostream>

int main(int argc, char const *argv[])
{
    int num1, num2;
    std::cout << "Please Input Two Integers:" << std::endl;
    std::cin >> num1 >> num2;
    if (num1 > num2)
    {
        while (num2 <= num1)
        {
            std::cout << num2 << std::endl;
            num2++;
        }
    }
    else
    {
        while (num1 <= num2)
        {
            std::cout << num1 << std::endl;
            num1++;
        }
    }

    return 0;
}
