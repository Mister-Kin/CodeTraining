#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;

    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* 你的代码将被嵌在这里 */
double f( int n, double a[], double x )
{
    double sum = 0,power = 1;
    sum = a[0];
    for (int y = 1; y <= n;y++)
    {
        power *= x;
        sum = sum + a[y] * power;
    }
    return sum;
}

/* 以下方法耗时过多，n=0时没必要也计算，直接令sum=a[0]
double f( int n, double a[], double x )
{
    double sum = 0;
    for (int y = 0; y <= n;y++)
    {
        double power = 1;
        if(y==0)
            power = 1;
        else
        {for (int i = 1; i <= y; i++)
            power *= x;}
        sum = sum + a[y] * power;
    }
    return sum;
}
*/
