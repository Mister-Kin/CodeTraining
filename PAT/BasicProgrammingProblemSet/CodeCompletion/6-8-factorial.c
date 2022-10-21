#include <stdio.h>

int Factorial( const int N );

int main()
{
    int N, NF;

    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");

    return 0;
}

/* 你的代码将被嵌在这里 */

int Factorial( const int N )
{
    if(N<0)
        return 0;
    if(N==0)
        return 1;
    int factorial=1;
    for (int i = 2; i <= N;i++)
        factorial *= i;
    return factorial;
}
