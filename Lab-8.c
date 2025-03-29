// 8.	Write a C program to find integration using trapezoidal rule.
#include <stdio.h>

// Function to be integrated
int f(int x)
{
    return (x * x * x + 2); // Example function
}
// Trapezoidal Rule Function
int trapezoidal(int a, int b)
{
    float h = (b - a);       // Step size
    float sum = f(a) + f(b); // First and last terms
    return (h / 2) * sum;    // Final result
}
int main()
{
    float a, b;
    printf("The Equation used for calcuation is:\nx^3+2*x+3\n");
    // Input lower and upper limits
    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    // Compute the integral
    float result = trapezoidal(a, b);
    // Output result
    printf("Approximate integral using Trapezoidal Rule: %.3f\n", result);
    printf("\nProgram By: KUSHAL DHAKAL");
    return 0;
}
