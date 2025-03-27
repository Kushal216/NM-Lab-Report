// program to demonstrate newton Raphson method
#include <stdio.h>
#include <conio.h>
#include <math.h>
float f(float x)
{
    return (x * x + 4 * x - 9);
}
float divf(float x)
{
    return (2 * x + 4);
}
int main()
{
    int i = 1;
    float a, b, E, Era;
        printf("The Equation used for calcuation is:\nx^2+4*x-9\n");
    printf("Enter the initial guess values:");
    scanf("%f", &a);
    printf("Enter the preecision value:");
    scanf("%f", &E);
    printf("%-3c| %6s%5c %6s%5c %7s%4c %7s\n", 'k', "x0", '|', "f(x0)", '|', "f'(x0)", '|', "Error");
    do
    {
        b = a - (f(a) / divf(a));
        Era = fabs((a - b) / b);
        printf("%-3d| %10f| %10f| %10f| %10f\n", i, a, f(a), divf(a), Era);
        a = b;
        i++;
    } while (Era > E);
    printf("\nThe approximated value of the root of the given function is : \n x = %f ", b);
    printf("\nProgram By: KUSHAL DHAKAL");    getch();
}
