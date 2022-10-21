#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;

    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */

int Count_Digit ( const int N, const int D )
{
    int ReplaceN = N;
    if(N==0)
    {   //此处建议加个括号，PAT的服务器环境GCC 6.5.0会没法很好识别匹配嵌套的if和else，不加大括号编译失败。
        if(D==N)
            return 1;
        else
            return 0;
    }
    int count = 0;
    while (ReplaceN != 0)
    {
        ReplaceN /= 10;
        count++;
    }
    if(N<0)
        ReplaceN = N * (-1);
    else
        ReplaceN = N;
    int CountSum = 0;
    for (int i = 0; i < count;i++)
    {
        if(D==ReplaceN%10)
            CountSum++;
        ReplaceN /= 10;
    }
    return CountSum;
}

/* 另一种思路判断数字位数
int t=10,count=0;
while(Replace/t)
{
    t*=10;
    count++;
}
*/
