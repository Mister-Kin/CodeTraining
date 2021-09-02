// 改写 1-4 的程序，将每个运算对象的打印操作放在一条独立的语句中。

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter two number: " << endl;
    int n1, n2;
    cin >> n1 >> n2;
    cout << "The product of ";
    cout << n1;
    cout << " and ";
    cout << n2;
    cout << " is ";
    cout << n1 * n2;
    cout << endl;
    return 0;
}
