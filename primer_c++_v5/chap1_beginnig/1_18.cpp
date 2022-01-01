// 统计输入中每个值的出现次数。
/*
1、输入全部相等的值：程序只会打印该相同的数值的次数。
2、输入没有重复的值：程序会打印每个数值，次数都为 1。
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << currVal << " occurs "
                          << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times" << std::endl;
    }

    return 0;
}
