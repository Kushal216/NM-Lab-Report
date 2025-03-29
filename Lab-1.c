#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(float x)
{
    return (3 * x * x - 6 * x + 2);
}
int i = 0;
int main()
{
    float a, b, c, E, Era;
    char sign;
    printf("The Equation used for calcuation is:\nx^3-6*x+2\n");
    printf("Enter the initial guess values:");
    scanf("%f%f", &a, &b);
    if (f(a) * f(b) > 0)
    {
        printf("Guess values are out of the range!!!");
        main();
    }
    printf("Enter the preecision value:");
    scanf("%f", &E);
    printf("USing the bisection Method:\n");

    do
    {
        c = ((a + b) / 2);
        sign = ((f(a) * f(c)) < 0) ? '-' : '+';
        printf("%-3d| %10f| %10f| %10f| %10f| %10f| %10f| %4c\n", i++, a, b, f(a), f(b), c, f(c), sign);
        if ((f(a) * f(c)) == 0)
        {
            c = (f(a)) ? c : a;
            break;
        }

        if (sign == '-')
            b = c;
        else
            a = c;

        Era = fabs((a - b) / b);

    } while (Era > E);
    printf("\nThe approximated value of the root of the given function is : \n x = %f ", c);
    printf("\n\nName : Kushal Dhakal\n");
    getch();
}
