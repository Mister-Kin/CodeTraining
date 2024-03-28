#include <format>
#include <iostream>

long long fact(long long i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    long long input_num;
    // long long类型最大值为2^63-1：9223372036854775807（19个数字），介于20和21阶乘结果之间。
    // 20的阶乘结果为:2432902008176640000（19个数字），21的阶乘结果为：51090942171709440000（20个数字）。
    std::cout << std::format("请输入一个1到20之间的数字，本程序会自动计算该数字的阶乘结果：");
    while (std::cin >> input_num)
    {
        if (input_num < 1 || input_num > 20)
        {
            std::cout << std::format("计算超出范围溢出，请输入1到20之间的数字，本程序会自动计算该数字的阶乘结果：");
            continue;
        }
        std::cout << std::format("{}的阶乘结果为:{}\n", input_num, fact(input_num)) << std::endl;
        std::cout << std::format("请入一个数字，本程序会自动计算该数字的阶乘结果：");
    }
}

int main(int argc, char const *argv[])
{
    interactive_fact();
    return 0;
}
