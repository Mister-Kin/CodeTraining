// 用 Sales_item.h 编写程序，读取多条销售记录，并统计每个 ISBN（每本书）的有几条销售记录。

#include "Sales_item.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_item sum, book;
    if (std::cin >> sum)
    {
        int count = 1;
        while (std::cin >> book)
        {
            if (sum.isbn == book.isbn)
            {
                count++;
                sum += book;
            }
            else
            {
                std::cout << sum.isbn << " sale "
                          << count << " times" << std::endl;
                sum = book;
                count = 1;
            }
        }
        std::cout << sum.isbn << " sale "
                  << count << " times" << std::endl;
    }

    return 0;
}
