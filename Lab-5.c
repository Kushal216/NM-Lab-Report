//5.	Write a C program to interpolate using Lagrange's method.
#include <stdio.h>
#include <math.h>
#include <conio.h>
#define MAX 10

int main()
{
    int i, j, n;
    float x[MAX], f[MAX], sum = 0, pro, xp, fp;
    printf("Enter the number of data points:\nn=  ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nInput the data points for x[%d]&f[%d]\n", i, i);
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("f[%d] = ", i);
        scanf("%f", &f[i]);
    }
    printf("\nInput the specified value of x: ");
    scanf("%f", &xp);
    for (i = 0; i <= n; i++)
    {
        pro = 1.0;
        for (j = 0; j <= n; j++)
        {
            if (i != j)
                pro = pro * (xp - x[j]) / (x[i] - x[j]);
        }
        sum = sum + pro * f[i];
    }
    fp = sum;
    printf("\nThe required functional value at %.3f = %.3f", xp, fp);
    printf("\nProgram By: KUSHAL DHAKAL");
    getch();
    return 0;
}
