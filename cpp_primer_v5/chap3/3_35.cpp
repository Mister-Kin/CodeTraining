#include <iostream>

using namespace std;

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
        array[i] = i;
    cout << "before: ";
    for (auto i : array)
        cout << i;
    cout << endl;

    for (int *begin = array, *end = &array[10]; begin != end; begin++)
        *begin = 0;
    cout << "after: ";
    for (auto i : array)
        cout << i;
    cout << endl;

    return 0;
}
