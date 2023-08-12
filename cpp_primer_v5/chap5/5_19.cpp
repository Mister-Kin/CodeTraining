#include <format>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string str1, str2;
    do
    {
        std::cout << "请输入两个字符串：";
        std::cin >> str1 >> str2;
        if (str1.size() > str2.size())
            std::cout << std::format("较短的字符串是{}\n", str2) << std::endl;
        else
            std::cout << std::format("较短的字符串是{}\n", str1) << std::endl;
    } while (std::cin);

    return 0;
}
