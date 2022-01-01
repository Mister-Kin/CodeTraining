#include <iostream>

int main()
{
    int data, sum = 0;
    while (std::cin >> data)
    {
        sum += data;
    }
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
