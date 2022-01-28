#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

bool compare_array(const int *begin1, const int *end1, const int *begin2, const int *end2);

int main()
{
    int array1[3] = {1, 2, 3};
    int array2[3] = {1, 2, 4};

    if (compare_array(begin(array1), end(array1), begin(array2), end(array2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};

    if (v1 == v2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}

bool compare_array(const int *begin1, const int *end1, const int *begin2, const int *end2)
{
    if ((end1 - begin1) != (end2 - begin2))
        return false;
    else
    {
        for (; (begin1 != end1) && (begin2 != end2); begin1++, begin2++)
            if (*begin1 != *begin2)
                return false;
    }
    return true;
}
