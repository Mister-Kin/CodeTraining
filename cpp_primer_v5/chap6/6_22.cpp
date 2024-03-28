#include <iostream>
#include <format>

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main(int argc, char const *argv[])
{
    int a = 1, b = 2;
    std::cout << std::format("交换前：a = {}, b = {}\n", a, b);
    swap(&a, &b);
    std::cout << std::format("交换后：a = {}, b = {}\n", a, b);
    return 0;
}
