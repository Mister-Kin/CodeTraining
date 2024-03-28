#include <iostream>

void print(int i)
{
    std::cout << i << std::endl;
}

void print(const int *beg, const int *end)
{
    while (beg != end)
        std::cout << *beg++ << std::endl;
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        std::cout << ia[i] << std::endl;
    }
}

// 这里的arr必须要有括号，这样才是声明为指向含有2个整数的数组的引用，没有括号就相当于引用的数组
void print(int (&arr)[2])
{
    for (auto i : arr)
        std::cout << i << std::endl;
}

int main(int argc, char const *argv[])
{
    int i = 0, j[2] = {0, 1};

    print(i);
    print(std::begin(j), std::end(j));
    print(j, std::end(j) - std::begin(j));
    print(j);

    return 0;
}
