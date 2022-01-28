#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("hello, world!");
    for (char c : str)
        c = 'X';
    cout << str << endl;

    return 0;
}
