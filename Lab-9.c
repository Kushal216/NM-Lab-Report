//9.	Write a C program to find integration using composite trapezoidal rule.
#include <stdio.h>
#include <math.h>
#define MAX 10
int f(int x)
{
    return (x* x * x + 2); // Example function
}

float trapezoidal(float a, float b, int n) {
	float h, sum = 0, Ig;
	int i;
    h = (b - a) / n; // Step size
    sum=f(a)+f(b);
	for (i = 0; i <= n; i++)
    {
       sum =sum+ f(a + i * h);
    }
//	for (i = 1; i <= n - 1; i++)
//        sum += f[i];
    Ig = h / 2 * sum;
    return Ig;
}
int main()
{
    int i, n;
    float a, b;
    printf("The Equation used for calcuation is:\nx^3+2\n");
    printf("Enter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);
    printf("Enter the no. of segments: ");
    scanf("%d", &n);

    printf("\nThe integration using composite trapezoidal rule is %.3f\n", trapezoidal(a,b,n));
    printf("Program By: KUSHAL DHAKAL");
    return 0;
}
