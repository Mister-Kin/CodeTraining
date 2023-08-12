#include <cctype>
#include <format>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str, pre_str;
    while (std::cin >> str)
    {
        if (str == pre_str && std::isupper(str[0]))
            break;
        else
            pre_str = str;
    }
    if (std::cin.eof())
        std::cout << std::format("没有任何单词是连续重复出现的") << std::endl;
    else
        std::cout << std::format("连续重复出现两次的单词为{}", str) << std::endl;

    return 0;
}
