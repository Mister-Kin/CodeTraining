// 从 cin 读取一组数，输出其和。

#include <iostream>

int main(int argc, char const *argv[])
{
    int data, sum = 0;
    while (std::cin >> data)
    {
        sum += data;
    }
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
