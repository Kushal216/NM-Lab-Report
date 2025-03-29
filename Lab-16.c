// 16.	Write a C program to solve ordinary differential equation using Euler's method.
#include <stdio.h>
#include <math.h>

#define f(x, y) (3 * (x) * (x) + 1) // 3x^2 + 1

int main()
{
    float x, y, h, xp, dy;
    int i, n;

    // Input initial values
    printf("The Equation used for calcuation is:\n3x^2+1\n");
    printf("Enter initial values of x and y: ");
    scanf("%f%f", &x, &y);

    // Input the value of x at which y is required
    printf("Enter x-value at which y is required: ");
    scanf("%f", &xp);

    // Input step-size
    printf("Enter step-size: ");
    scanf("%f", &h);

    // Calculate the number of iterations
    n = (xp - x) / h;

    // Print table header
    printf("\nIteration\t x\ty\tdy\ty_new\n");
    printf("------------------------------------------------------------\n");

    // Iteration to apply Euler's method
    for (i = 1; i <= n; i++)
    {
        dy = h * f(x, y); // dy = h * f(x, y)

        // Calculate the new values of x and y
        float y_new = y + dy;

        // Print each iteration's result
        printf("%d\t\t%.4f\t%.4f\t%.4f\t%.4f\n", i, x, y, dy, y_new);

        // Update x and y for the next iteration
        x = x + h;
        y = y_new;
    }

    // Output the final result
    printf("\nThe value of y at x=%.2f is %.4f\n", x, y);
    printf("Program By: KUSHAL DHAKAL\n");

    return 0;
}
