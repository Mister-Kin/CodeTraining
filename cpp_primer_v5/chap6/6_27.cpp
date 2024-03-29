#include <iostream>

long long int sum(std::initializer_list<int> const &li)
{
    long long int sum = 0;
    for (auto it = li.begin(); it != li.end(); it++)
    {
        sum += *it;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    auto li = {1, 2, 3};
    std::cout << sum(li) << std::endl;

    return 0;
}
