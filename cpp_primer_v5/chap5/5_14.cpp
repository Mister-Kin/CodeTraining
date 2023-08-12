#include <format>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str, pre_str;
    unsigned cnt = 0;
    std::pair<std::string, unsigned> max_occurred;
    while (std::cin >> str)
    {
        if (str == pre_str)
            ++cnt;
        else
            cnt = 0;
        if (cnt > max_occurred.second)
            max_occurred = {str, cnt};
        pre_str = str;
    }
    if (max_occurred.second == 0)
        std::cout << std::format("没有任何单词重复出现") << std::endl;
    else
        std::cout << std::format("单词{}连续出现{}次", max_occurred.first, max_occurred.second + 1) << std::endl;

    return 0;
}
