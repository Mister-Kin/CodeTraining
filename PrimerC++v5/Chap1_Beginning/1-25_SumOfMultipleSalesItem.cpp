// 用 Sales_item.h 编写程序，读取多条销售记录，并统计每本书的销售报告。

#include "Sales_item.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (total.isbn == trans.isbn)
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No Data?!" << std::endl;
        return -1;
    }

    return 0;
}
