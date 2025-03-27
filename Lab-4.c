// Program to implement Fixed Point Iteration Method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x)
{
   return 1 + 0.5 * sin(x);
}

int main()
{
   int i = 0;
   float x0, x1, E, Era;

   printf("\nf(x)=1+(1/2)sinx-x\n\nIn form x=g(x):\ng(x)=1+(1/2)sinx\n\nEnter an initial guess for the function : ");
   scanf("%f", &x0);

   printf("\nEnter the precision required : ");
   scanf("%f", &E);

   printf("Using Fixed Point Iteration Method : \n\n");

   printf("%-3c| %6s%5c %6s%5c %7s\n", 'k', "x0", '|', "g(x0)", '|', "x1");
   do
   {
      x1 = f(x0);
      printf("%-3d| %10f| %10f| %10f\n", i++, x0, f(x0), x1);
      Era = fabs((x1 - x0) / x1);
      x0 = x1;
   } while (Era > E);

   printf("\nThe approximated value of the root of the given function is : \n x = %f ", x1);

   printf("Program By: KUSHAL DHAKAL");
   return 0;
}