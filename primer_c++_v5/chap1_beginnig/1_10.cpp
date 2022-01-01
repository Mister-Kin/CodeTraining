// 使用递减运算符 --，在循环中按递减顺序打印 10 到 0 之间的整数。

#include <iostream>

int main(int argc, char const *argv[])
{
    int i = 10;
    while (i >= 0)
    {
        std::cout << i << std::endl;
        i--;
    }
    return 0;
}
