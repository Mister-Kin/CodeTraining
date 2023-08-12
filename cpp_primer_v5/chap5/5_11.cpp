#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
    char ch;
    while (std::cin >> std::noskipws >> ch)
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++newLineCnt;
            break;
        }
    std::cout << std::format("Number of vowel a(A): {}\n", aCnt);
    std::cout << std::format("Number of vowel e(E): {}\n", eCnt);
    std::cout << std::format("Number of vowel i(I): {}\n", iCnt);
    std::cout << std::format("Number of vowel o(O): {}\n", oCnt);
    std::cout << std::format("Number of vowel u(U): {}\n", uCnt);
    std::cout << std::format("Number of vowel space: {}\n", spaceCnt);
    std::cout << std::format("Number of vowel tab: {}\n", tabCnt);
    std::cout << std::format("Number of vowel new line: {}\n", newLineCnt) << std::endl;

    return 0;
}
