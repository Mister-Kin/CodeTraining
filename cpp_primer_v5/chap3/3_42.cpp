#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 1);
    int array[10];
    for (size_t i = 0; i != v.size(); i++)
        array[i] = v[i];
    for (auto i : array)
        cout << i << " ";
    cout << endl;
    return 0;
}
