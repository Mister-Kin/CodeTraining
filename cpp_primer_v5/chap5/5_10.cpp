#include <format>
#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (std::cin >> ch)
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
        }
    std::cout << std::format("Number of vowel a(A): {}\n", aCnt);
    std::cout << std::format("Number of vowel e(E): {}\n", eCnt);
    std::cout << std::format("Number of vowel i(I): {}\n", iCnt);
    std::cout << std::format("Number of vowel o(O): {}\n", oCnt);
    std::cout << std::format("Number of vowel u(U): {}\n", uCnt) << std::endl;

    return 0;
}
