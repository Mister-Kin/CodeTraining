// 使用 for 循环重做 1-9 到 1-11 的练习。
/*
对比 for 循环和 while 循环的优缺点：for 循环的变量可以在语句中定义，而 while 语句中直接就是判断循环的条件，无法在语句中定义变量。如此看来，for 语句中定义的变量所占用的内存可以在循环结束后回收，减少了内存的占用。

常见的编译错误：
1、语法错误（syntax error）：比如 main 参数列表漏掉括号；语句结束之处用冒号而非分号；字符串字面值常量两侧漏掉引号。
2、类型错误（type error）：比如向一个期望参数为 int 的函数传递一个字符串字面值常量。
3、声明错误（declaration）：比如对来自标准库的名字忘记使用 std:: 以及标识符名字拼写错误。
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = 50; i <= 100; i++)
        sum += i;
    std::cout << "The sum of 50 to 100 is "
              << sum << std::endl;
    for (int i = 10; i >= 0; i--)
        std::cout << i << std::endl;
    std::cout << "Please Input Two Integer: ";
    int num1, num2;
    std::cin >> num1 >> num2;
    if (num1 > num2)
    {
        for (; num2 <= num1; num2++)
            std::cout << num2 << std::endl;
    }
    else
    {
        for (; num1 <= num2; num1++)
            std::cout << num1 << std::endl;
    }

    return 0;
}
