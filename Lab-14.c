// 14.	Write a C program to find integral value by using Gaussian Integration.
#include <stdio.h>
#include <math.h>
#define f(x) (exp(x))
int main()
{
    int i, n = 2;
    float a, b, c, k[5], x[5], z[5], w[5], Ig = 0;
    printf("The Equation used for calcuation is:\ne^x\n");

    printf("Enter the Lower & Upper Limits: ");
    scanf("%f%f", &a, &b);
    z[0] = -1 / sqrt(3);
    z[1] = -z[0];
    w[0] = w[1] = 1;
    c = (b - a) / 2;
    for (i = 0; i < n; i++)
        x[i] = c * z[i] + (b + a) / 2;
    for (i = 0; i < n; i++)
    {
        k[i] = f(x[i]);
        Ig += w[i] * k[i];
    }
    Ig = c * Ig;
    printf("Integration Value by using 2-point Gaussian formula: %f", Ig);
    printf("\n\nProgram By: KUSHAL DHAKAL");
    return 0;
}
