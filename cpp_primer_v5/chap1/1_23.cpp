#include "Sales_item.h"
#include <iostream>

int main()
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
