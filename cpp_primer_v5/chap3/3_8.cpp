#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("hello, world!");

    decltype(str.size()) i = 0;

    while (i < str.size())
        str[i++] = 'X';

    cout << str << endl;

    for (i = 0; i < str.size(); str[i++] = 'Y')
        ;
    cout << str << endl;

    return 0;
}
