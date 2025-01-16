#include <stdio.h>

#define MAXN 10

int Sum(int List[], int N);

int main()
{
    int List[MAXN], N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &List[i]);
    printf("%d\n", Sum(List, N));

    return 0;
}

/* 你的代码将被嵌在这里 */

int Sum(int List[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += List[i];
    return sum;
}

/* 以下是错误的。
for循环中应为i<N，注意main函数最后赋值的下标，即需要保持和main函数中for循环的条件一致。
int Sum ( int List[], int N )
{
    int sum = 0;
    for (int i = 0; i <= N;i++)
        sum += List[i];
    return sum;
}
*/
