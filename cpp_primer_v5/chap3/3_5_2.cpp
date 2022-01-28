#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str;
    for (string buff; cin >> buff; str += (str.empty() ? "" : " ") + buff) // 空串时，加""就当于没加任何内容
        ;
    cout << "The concatenated string is " << str << endl;

    return 0;
}
