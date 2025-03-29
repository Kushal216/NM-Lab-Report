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
   float x0, x1, x2, E, Era;
   char sign;
   printf("The Equation used for calcuation is:\nx^3-6*x+2\n");
   printf("Enter the initial guess values:");
   scanf("%f%f", &x1, &x0);

   printf("Enter the preecision value:");
   scanf("%f", &E);
   printf("USing the Secant Method:\n");
   printf("%3c| %6s%5c %6s%5c %7s%4c %7s%2c %6s\n", 'k', "xk", '|', "x(k-1)", '|', "f(xk)", '|', "f(x(k-1))", '|', "x(k+1)");

   do
   {
      x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));
      Era = fabs((x1 - x0) / x1);

      printf("%3d| %10f| %10f| %10f| %10f| %10f\n", i++, x1, x0, f(x1), f(x0), x2);
      x0 = x1;
      x1 = x2;

   } while (Era > E);

   printf("\nThe approximated value of the root of the given function is : \n x = %f .", x2);
   printf("\nProgram By: KUSHAL DHAKAL");
   getch();
}
