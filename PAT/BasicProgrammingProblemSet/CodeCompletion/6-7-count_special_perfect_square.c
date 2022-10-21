#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;

    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */

int IsTheNumber ( const int N )
{
    int result = (int)sqrt(N);
    int SquareRoot = result * result == N;

    int ReplaceN = N, SameNumber=0;
    int ArrayTest[10];
    for (int i=0; i < 10;i++)
    {
        ArrayTest[i] = 0;
    }
    while (ReplaceN != 0)
    {
        if(ArrayTest[ReplaceN%10]==1)
        {
            SameNumber = 1;
            break;
        }
        ArrayTest[ReplaceN % 10] = 1;
        ReplaceN /= 10;
    }

    return SquareRoot && SameNumber;
}
