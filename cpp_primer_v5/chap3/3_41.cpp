#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    int array[] = {1, 2, 3};
    vector<int> v(begin(array), end(array));
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
