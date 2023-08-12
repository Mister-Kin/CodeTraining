#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, pre_ch = '\0';
    while (std::cin >> std::noskipws >> ch)
    {

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
            if (pre_ch == 'f')
                ++fiCnt;
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
        case 'f':
            if (pre_ch == 'f')
                ++ffCnt;
            break;
        case 'l':
            if (pre_ch == 'f')
                ++flCnt;
            break;
        }
        pre_ch = ch;
    }
    std::cout << std::format("Number of vowel a(A): {}\n", aCnt);
    std::cout << std::format("Number of vowel e(E): {}\n", eCnt);
    std::cout << std::format("Number of vowel i(I): {}\n", iCnt);
    std::cout << std::format("Number of vowel o(O): {}\n", oCnt);
    std::cout << std::format("Number of vowel u(U): {}\n", uCnt);
    std::cout << std::format("Number of vowel space: {}\n", spaceCnt);
    std::cout << std::format("Number of vowel tab: {}\n", tabCnt);
    std::cout << std::format("Number of vowel new line: {}\n", newLineCnt);
    std::cout << std::format("Number of ff: {}\n", ffCnt);
    std::cout << std::format("Number of fl: {}\n", flCnt);
    std::cout << std::format("Number of fi: {}\n", fiCnt) << std::endl;

    return 0;
}
