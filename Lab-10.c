
//10.	Write a C program to find integration using Simpson's 1/3 l rule.#include <stdio.h>
#include <math.h>
#include<stdio.h>
int f(int x)
{
    return (x* x * x + 2*x+3); // Example function
}
float simpson(float a, float b) {
	int i,n=2;
	float h = (b - a) / n;
    float Ig = h / 3 * (f(0) + f(b) + 4 * f(a));
    return Ig;
}

int main()
{
    int i;
    float a, b;
    printf("The Equation used for calcuation is:\nx^3+2*x+3\n");
    printf("Enter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);

    printf("\nThe integration using Simpson's 1/3 rule is %.3f\n", simpson(a,b));
    printf("Program By: KUSHAL DHAKAL");
    return 0;
}
