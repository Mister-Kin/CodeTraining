// 判断下面程序片段是否合法。
/*
错误分析：分号“ ; ”前的语句会被处理成一条语句，所有第二、第三行没有 cout 对象，所以不合法。
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << endl;
*/

#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "Enter two number: " << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;

    /* ---- 修正代码块 ---- */
    std::cout << "The sum of " << v1;
    std::cout << " and " << v2;
    std::cout << " is " << v1 + v2 << std::endl;
    /* ---- 代码块结束 ---- */

    return 0;
}
