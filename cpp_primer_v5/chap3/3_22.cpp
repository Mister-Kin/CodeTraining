#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> text;
    text.push_back("aa aa aa");
    text.push_back("");
    text.push_back("bb bb bb");

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto &c : *it)
        {
            if (isalpha(c))
                c = toupper(c);
        }
    }

    for (auto it : text)
    {
        cout << it << endl;
    }
    return 0;
}
