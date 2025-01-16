#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Average(ElementType S[], int N);

int main()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &S[i]);
    printf("%.2f\n", Average(S, N));

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Average(ElementType S[], int N)
{
    ElementType sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += S[i];
    }
    ElementType average;
    average = sum / N;
    return average;
}

/* 以下是错误的。
for循环中应为i<N，注意main函数最后赋值的下标，即需要保持和main函数中for循环的条件一致。
ElementType Average( ElementType S[], int N )
{
    ElementType sum = 0;
    for (int i = 0; i <= N;i++)
    {
        sum += S[i];
    }
    ElementType average;
    average = sum / N;
    return average;
}
*/
