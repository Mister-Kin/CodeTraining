#include <iostream>

using namespace std;

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
        array[i] = i;

    for (auto i : array)
        cout << i;
    cout << endl;
    return 0;
}
