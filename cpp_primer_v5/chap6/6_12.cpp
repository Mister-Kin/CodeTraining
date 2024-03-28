#include <iostream>
#include <format>

void swap(int &val1, int &val2)
{
    int tmp;
    tmp = val1;
    val1 = val2;
    val2 = tmp;
}

int main(int argc, char const *argv[])
{
    for (int val1, val2; std::cout << std::format("请输入两个值（以中间空格隔开）："), std::cin >> val1 >> val2;)
    {
        std::cout << std::format("交换前的值：{}，{}。\n", val1, val2);
        swap(val1, val2);
        std::cout << std::format("交换后的值：{}，{}。\n", val1, val2);
    }

    return 0;
}
