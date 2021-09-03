// 用 Sales_item.h 编写程序，读取一组书籍销售记录，将每条记录打印到标准输出上。

#include "Sales_item.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_item book;
    while (std::cin >> book)
    {
        std::cout << book << std::endl;
    }

    return 0;
}
