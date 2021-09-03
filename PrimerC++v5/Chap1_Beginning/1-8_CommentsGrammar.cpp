// 指出下列哪些输出语句是合法的。预测编译这些语句会产生什么结果，实际编译来验证。

#include<iostream>

int main(int argc, char const *argv[])
{
    std::cout << "/*";
    std::cout << "*/";
    //std::cout << /* "*/" */; // 不合法
    //std::cout<< /* "*/" /* "*/" */; // 不合法
    return 0;
}
