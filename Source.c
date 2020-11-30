#include <stdio.h>
#include <math.h>
#define n 5

void calc(int a[n][n]);
void arith_mean(int a[n][n]);
void main(int b)
{
    int i, j, q = 0;
    static int a[n][n];
    printf("Own values (1) or constants (else): ");
    scanf_s("%d", &q);
    
    if (q == 1) {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("a[%d][%d] =", i + 1, j + 1);
                scanf_s("%5d", &a[i][j]);
            }
        }
    }
    else {
    for (i = 0; i < 30; i++)
    {
        if (i < 5) {
            a[i][0] = (i + 1);
        }
        else if (i < 10) {
            a[i - 5][4] = (i + 1);
        }
        else if (i < 15) {
            a[i - 10][3] = (i + 1);
        }
        else if (i < 20) {
            a[i - 15][1] = (i + 1);
        }
        else if (i < 25) {
            a[i - 20][2] = (i + 1);
        }
    }
}
    printf("OLD\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    calc(a);

    printf("\nNEW\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    arith_mean(a);
    return 0;
}

void arith_mean(int a[n][n])
{
    int i, j = 0, diag = 0, sum = 0, multy = 1, tmpmul = 0,addmul=0;
    float ar_mean;
    printf("\nSUM");
    for (i = 1; i < n; ++i)
    {
        tmpmul = a[i][j];
        for (j = 0; j <= diag && diag < n; ++j)
        {
            sum += a[i][j];
            printf("%5d", sum);
            multy *= a[i][j];
        }
        diag++;
    }
    ar_mean = sum / 10;
    printf("\n\nArithmetic mean: %.2f", ar_mean);
    printf("\n\nProduct (dobutok): %.2d\n", multy);
}

void calc(int a[n][n])
{
    int i = 0, j = 0, iter = 0, tmpval;
    for (i = 0; i < n; ++i)
    {
        for (iter = 1; iter < n; ++iter)
        {
            tmpval = a[i][iter];
            for (j = (iter - 1); a[i][j] > tmpval; --j)
            {
                a[i][j + 1] = a[i][j];

            }
            a[i][j+1] = tmpval;
        }
    }
}

//SOME TEST TEXT
