#include <iostream>

void reset(int &i)
{
    i = 0;
}

int main(int argc, char const *argv[])
{
    int i = 42;
    reset(i);
    std::cout << i << std::endl;
    return 0;
}
