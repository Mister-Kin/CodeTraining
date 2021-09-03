// 使用 while 循环，50 到 100 的整数相加。

#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 50, sum = 0;
    while (i <= 100)
    {
        sum += i;
        i++;
    }
    std::cout << "Sum of 50 to 100 inclusive is"
              << sum << std::endl;
    return 0;
}
