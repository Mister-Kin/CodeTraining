// 用 Sales_item.h 编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。

#include "Sales_item.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_item sum, book;
    if (std::cin >> sum)
    {
        while (std::cin >> book)
        {
            sum += book;
        }
    }
    std::cout << sum << std::endl;

    return 0;
}
