#include <format>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};

    for (int grade = 0; std::cin >> grade;)
    {
        if (grade < 0 || grade > 100)
        {
            std::cout << std::format("输入错误，请重新输入0-100之间的整数：") << std::endl;
            continue;
        }

        std::string letter = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
        letter += (grade == 100 || grade < 60) ? "" : (grade % 10 > 7) ? "+"
                                                  : (grade % 10 < 3)   ? "-"
                                                                       : "";

        std::cout << std::format("成绩为{}", letter) << std::endl;
    }
    return 0;
}
