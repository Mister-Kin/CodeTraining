#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1 == str2)
            cout << "The two strings are equal." << endl;
        else
            cout << "The longer string is " << ((str1.size() > str2.size()) ? str1 : str2) << endl;
    }

    return 0;
}
