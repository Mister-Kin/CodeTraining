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
        for (decltype(vec.size()) i = 0; i < vec.size() - 1; i++)
            cout << vec[i] + vec[i + 1] << " ";
        cout << endl;
    }

    // 注意这种方式的下标类型不能用decltype(vec.size())，因为当输入只有一个数时，j--就会变成-1，不仅i<j成立，而且vec[j]也非法了。
    cout << "head and tail integer: ";
    for (int i = 0, j = vec.size() - 1; i <= j; i++, j--)
        cout << vec[i] + vec[j] << " ";
    cout << endl;

    /*
    // 下标类型用decltype(vec.size())时，请用这种方式访问下标
    auto size = (vec.size() + 1) / 2;
    for (decltype(vec.size()) i = 0; i != size; ++i)
        cout << vec[i] + vec[vec.size() - i - 1] << " ";
    cout << endl;
    */

    return 0;
}
