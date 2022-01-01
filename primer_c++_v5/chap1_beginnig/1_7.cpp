// 编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

int main(int argc, char const *argv[])
{
    /* /* 错误注释 */ 错误注释 */
    return 0;
}
