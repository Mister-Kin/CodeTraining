#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Max( ElementType S[], int N );

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));

    return 0;
}

/* 你的代码将被嵌在这里 */

ElementType Max( ElementType S[], int N )
{
    ElementType MaxNum = S[0];
    for (int i = 1; i < N; i++)
    {
        if(S[i]>=MaxNum)
            MaxNum = S[i];
    }
    return MaxNum;
}

/* 第一个MaxNum应该设为数组里的元素，设为0且全为负数时，没法输出最大值。for循环中应为i<N，看main函数最后赋值的下标。这个细节在6-5之前都没多加注意。
ElementType Max( ElementType S[], int N )
{
    ElementType MaxNum = 0;
    for (int i = 0; i <= N;i++)
    {
        if(S[i]>=MaxNum)
            MaxNum = S[i];
    }
    return MaxNum;
}
*/
