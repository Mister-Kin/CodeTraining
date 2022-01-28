#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    const char cs1[] = "abc", cs2[] = "abcd";
    char result[10];
    strcpy(result, cs1);
    strcat(result, cs2);
    cout << result << endl;
    return 0;
}
