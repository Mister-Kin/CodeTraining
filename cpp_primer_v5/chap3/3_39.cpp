#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "abc", s2 = "abcd";
    if (s1 == s2)
    {
        cout << "the two strings are equal.";
    }
    else if (s1 > s2)
    {
        cout << s1 << " is bigger than " << s2;
    }
    else
        cout << s1 << " is smaller than " << s2;
    cout << endl;

    const char cs1[] = "abcd", cs2[] = "abc";
    auto compare_result = strcmp(cs1, cs2);
    if (compare_result == 0)
    {
        cout << "the two strings are equal.";
    }
    else if (compare_result > 0)
    {
        for (auto i : cs1)
            if (i != '\0')
                cout << i;
        cout << " is bigger than ";
        for (auto i : cs2)
            if (i != '\0')
                cout << i;
    }
    else
    {
        for (auto i : cs1)
            if (i != '\0')
                cout << i;
        cout << " is smaller than ";
        for (auto i : cs2)
            if (i != '\0')
                cout << i;
    }

    return 0;
}
