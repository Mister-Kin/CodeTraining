#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(10, 5);

    for (auto item = vec.begin(); item != vec.end(); item++)
        *item *= 2;

    for (auto i : vec)
        cout << i << " ";
    cout << endl;
    return 0;
}
