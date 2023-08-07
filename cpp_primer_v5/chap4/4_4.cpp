#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    int result = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    std::cout << std::format("Expression: 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2 equals {}.\n", result);
    return 0;
}
