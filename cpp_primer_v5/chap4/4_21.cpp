#include <format>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> veci{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto &i : veci)
        std::cout << std::format("{} ", (i % 2) != 0 ? i *= 2 : i);
    std::cout << std::endl;
    return 0;
}
