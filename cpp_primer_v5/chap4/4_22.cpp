#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    for (unsigned score; std::cin >> score;)
    {
        auto result = score > 90 ? "high pass" : score > 75 ? "pass"
                                             : score >= 60  ? "low pass"
                                                            : "fail";
        std::cout << std::format("条件运算符版本：{}", result) << std::endl;

        if (score > 90)
            auto result = "high pass";
        else if (score > 75)
            auto result = "pass";
        else if (score >= 60)
            auto result = "low pass";
        else
            auto result = "fail";
        std::cout << std::format("if-else语句版本：{}", result) << std::endl;
    }
    return 0;
}
