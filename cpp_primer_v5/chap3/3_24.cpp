#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vec;
    for (int i; cin >> i; vec.push_back(i))
        ;

    if (vec.empty())
    {
        cout << "input at least one integer." << endl;
        return -1;
    }

    if (vec.size() == 1)
    {
        cout << "only one integer " << vec[0] << ", it doesn't have any adjacent elements." << endl;
    }
    else
    {
        cout << "adjacent integer: ";
        for (auto item = vec.begin(); item != vec.end() - 1; item++)
            cout << *item + *(item + 1) << " ";
        cout << endl;
    }

    cout << "head and tail integer: ";
    auto beg = vec.cbegin(), end = vec.cend();
    for (auto mid = (beg + (end - beg + 1) / 2); beg != mid; beg++)
        cout << *beg + *(end - 1 - (beg - vec.cbegin())) << " ";
    cout << endl;

    return 0;
}
