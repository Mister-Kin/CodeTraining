#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    double cm, CalcFoot;
    cin >> cm;
    CalcFoot = cm / (100 * 0.3048 * (145 / 144));
    int inch, foot;
    foot = (int)CalcFoot;
    inch = (int)((CalcFoot-foot)*12);
    cout << foot << " " << inch << endl;
    return 0;
}

/*
    这题语义不清，有很大的坑。实际要求输出的是 cm 数据对应英制长度的整数值。
    例如 cm 换算成 foot 后肯定带有小数，输出 foot 直接输出其整数部分即可，其小数部分换算成 inch 后再输出其整数，而不是将 cm 换算成 inch 后再输出整数。
*/
