#include <stdio.h>
#include <math.h>
#define f(x) (pow(x, 3) + 1)

int main()
{
    int i, n = 3;
    float a, b, f[3], h, Ig;
    printf("The Equation used for calcuation is:\nx^3+1\n");
    printf("Enter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);
    h = (b - a) / n;
    for (i = 0; i <= n; i++)
        f[i] = f(a + i * h);
    Ig = 3 * h / 8 * (f[0] + f[n] + 3 * (f[1] + f[2]));
    printf("Using Simpson's 3/8 rule:\n");
    printf("The integration is %f\n", Ig);
    printf("Program By: KUSHAL DHAKAL");
    return 0;
}
