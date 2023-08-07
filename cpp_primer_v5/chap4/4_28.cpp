#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << std::format("bool:\t{} bytes", sizeof(bool)) << std::endl;
    std::cout << std::format("char:\t{} bytes", sizeof(char)) << std::endl;
    std::cout << std::format("wchar_t:\t{} bytes", sizeof(wchar_t)) << std::endl;
    std::cout << std::format("char16_t:\t{} bytes", sizeof(char16_t)) << std::endl;
    std::cout << std::format("char32_t:\t{} bytes", sizeof(char32_t)) << std::endl;
    std::cout << std::format("short:\t{} bytes", sizeof(short)) << std::endl;
    std::cout << std::format("int:\t{} bytes", sizeof(int)) << std::endl;
    std::cout << std::format("long:\t{} bytes", sizeof(long)) << std::endl;
    std::cout << std::format("long long:\t{} bytes", sizeof(long long)) << std::endl;
    std::cout << std::format("float:\t{} bytes", sizeof(float)) << std::endl;
    std::cout << std::format("double:\t{} bytes", sizeof(double)) << std::endl;
    std::cout << std::format("long double:\t{} bytes", sizeof(long double)) << std::endl;
    return 0;
}
