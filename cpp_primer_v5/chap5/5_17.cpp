#include <iostream>
#include <vector>

bool is_prefix(const std::vector<int> &first, const std::vector<int> &second)
{
    if (first.size() > second.size())
        return is_prefix(second, first);
    for (unsigned i = 0; i < first.size(); ++i)
        if (first[i] != second[i])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    std::vector<int> first{0, 1, 1, 2};
    std::vector<int> second{0, 1, 1, 2, 3, 5, 8};
    std::cout << (is_prefix(first, second) ? "yes\n" : "no\n") << std::endl;

    return 0;
}
