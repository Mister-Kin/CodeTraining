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
    vector<string> v;
    for (string str; cin >> str; v.push_back(str))
        ;

    for (auto str : v)
        cout << str << endl;
    return 0;
}
