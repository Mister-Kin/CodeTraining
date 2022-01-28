#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    for (string str; cin >> str; cout << str << endl)
        ;
    return 0;
}
