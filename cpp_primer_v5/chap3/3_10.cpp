#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

int main()
{
    cout << "Enter a string of characters including punctuation: ";
    for (string s; getline(cin, s); cout << endl)
        for (auto i : s)
            if (!ispunct(i))
                cout << i;

    return 0;
}
