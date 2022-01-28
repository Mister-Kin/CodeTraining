#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
        array[i] = i;
    int new_array[10];
    for (int i = 0; i < 10; i++)
        new_array[i] = array[i];
    for (auto i : new_array)
        cout << i;
    cout << endl;

    vector<int> v(10);
    for (int i = 0; i != 10; ++i)
        v[i] = array[i];
    vector<int> v2(v);
    for (auto i : v2)
        cout << i;
    cout << endl;
    return 0;
}
