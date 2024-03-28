#include <iostream>
#include <cctype>
#include <string>

bool HasUpper(const std::string &s)
{
    for (auto c : s)
    {
        if (std::isupper(c))
            return true;
    }
    return false;
}

void ToLower(std::string &s)
{
    for (auto &c : s)
    {
        c = std::tolower(c);
    }
}

int main(int argc, char const *argv[])
{
    std::string s = "Hello";
    std::cout << std::boolalpha << HasUpper(s) << std::endl;
    ToLower(s);
    std::cout << s << std::endl;

    return 0;
}
