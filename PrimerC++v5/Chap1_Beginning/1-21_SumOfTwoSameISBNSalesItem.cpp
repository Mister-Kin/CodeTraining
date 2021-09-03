// 用 Sales_item.h 编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出总和。

#include "Sales_item.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;

    return 0;
}
