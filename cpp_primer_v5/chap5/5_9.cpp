#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (std::cin >> ch)
    {
        if (ch == 'a')
            ++aCnt;
        else if (ch == 'e')
            ++eCnt;
        else if (ch == 'i')
            ++aCnt;
        else if (ch == 'o')
            ++oCnt;
        else if (ch == 'u')
            ++uCnt;
    }
    std::cout << std::format("Number of vowel a: {}\n", aCnt);
    std::cout << std::format("Number of vowel e: {}\n", eCnt);
    std::cout << std::format("Number of vowel i: {}\n", iCnt);
    std::cout << std::format("Number of vowel o: {}\n", oCnt);
    std::cout << std::format("Number of vowel u: {}\n", uCnt) << std::endl;

    return 0;
}
