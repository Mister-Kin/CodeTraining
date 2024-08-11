#include <iostream>
#include <vector>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main(int argc, char const *argv[])
{
    int func(int, int);
    std::vector<decltype(func) *> vec1;
    vec1.push_back(add);
    vec1.push_back(subtract);
    vec1.push_back(multiply);
    vec1.push_back(divide);

    for (auto i : vec1)
    {
        std::cout << i(3, 3) << ", "; // 8, 4, 12, 3
    }
    std::cout << std::endl;
    return 0;
}
