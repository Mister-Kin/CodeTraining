#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str;
    vector<string> v;
    while (cin >> str)
    {
        v.push_back(str);
    }
    for (auto &str : v)
    {
        for (auto &c : str)
            c = toupper(c);
        cout << str << endl;
    }

    return 0;
}
