// 分析下面 for 循环完成的功能和 sum 的终值。 sum 终值为 0。

#include <iostream>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = -100; i <= 100; ++i)
        sum += i;
    std::cout << sum;
    return 0;
}
