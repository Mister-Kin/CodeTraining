#include <iostream>
#include <string>

bool str_subrange(const std::string &str1, const std::string &str2)
{
    if (str1.size() != str2.size())
        return str1 == str2;
    auto size(str1.size() < str2.size() ? str1.size() : str2.size());
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return;
    }
}

int main(int argc, char const *argv[])
{
    std::string str1, str2;
    str1 = "hello";
    str2 = "hello";
    std::cout << str_subrange(str1, str2) << std::endl;
    str2 = "helloo";
    std::cout << str_subrange(str1, str2) << std::endl;
    return 0;
}
