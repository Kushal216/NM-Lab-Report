// 19.	Write a C program for solving system of equations using basic Gauss elimination method.
#include <stdio.h>
#include <math.h>
#define MAX 10

void inputMatrix(int n, float a[MAX][MAX])
{
    int i, j;
    printf("Enter %dx%d elements for the augmented matrix:\n", n, n + 1);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + 1; j++)
            scanf("%f", &a[i][j]);
}

void printMatrix(int n, float a[MAX][MAX])
{
    int i, j;
    printf("\nCurrent Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
}

void gaussElimination(int n, float a[MAX][MAX])
{
    int i, j, k;
    float c;

    printf("\nPerforming Gauss Elimination:\n");
    for (k = 1; k <= n; k++)
    {
        for (i = k + 1; i <= n; i++)
        {
            c = a[i][k] / a[k][k];
            for (j = k; j <= n + 1; j++)
                a[i][j] -= c * a[k][j];
        }
        printMatrix(n, a);
    }

    float x[MAX];
    for (i = n; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    printf("\nThe solution set is:\n");
    for (i = 1; i <= n; i++)
        printf("x[%d] = %.4f\n", i, x[i]);
}

int main()
{
    int n;
    float a[MAX][MAX];

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    inputMatrix(n, a);
    printMatrix(n, a);
    gaussElimination(n, a);

    printf("\nProgram By: KUSHAL DHAKAL\n");
    return 0;
}
