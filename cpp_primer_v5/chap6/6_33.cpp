#include <iostream>
#include <vector>

using Iter = std::vector<int>::const_iterator;

void print(Iter first, Iter last)
{
    if (first == last)
    {
        std::cout << "over!" << std::endl;
        return;
    }
    std::cout << *first << " ";
    print(++first, last);
}
int main(int argc, char const *argv[])
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec.cbegin(), vec.cend());

    return 0;
}
