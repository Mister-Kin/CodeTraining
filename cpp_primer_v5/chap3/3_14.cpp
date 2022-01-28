#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> v;
    for (int i; cin >> i; v.push_back(i))
        ;

    for (auto i : v)
        cout << i << endl;
    return 0;
}
