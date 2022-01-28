#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("hello, world!");
    for (auto &c : str)
        c = 'X';
    cout << str << endl;

    return 0;
}
