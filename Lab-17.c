//17.	Write a C program to solve ordinary differential equation using Heun's method.                                          
#include <stdio.h>
#include <math.h>

#define f(x, y) (2 * (y) / (x)) //   2y/x

int main()
{
    float x, y, h, xp, m1, m2;
    int i, n;
    
    // Input initial values
            printf("The Equation used for calcuation is:\n2y/x\n");
    printf("Enter initial values of x and y: ");
    scanf("%f%f", &x, &y);
    
    // Input the value of x at which y is required
    printf("Enter x-value at which y is required: ");
    scanf("%f", &xp);
    
    // Input step-size
    printf("Enter step-size: ");
    scanf("%f", &h);
    
    // Calculate the number of iterations
    n = ((xp - x) / h);
    
    // Print table header
    printf("\nIteration\tx\ty\tm1\tm2\ty_new\n");
    printf("---------------------------------------------------------------\n");
    
    // Iteration to apply Heun's method
    for (i = 1; i <= n; i++)
    {
        m1 = f(x, y);  // Slope at (x, y)
        m2 = f(x + h, y + (m1 * h));  // Slope at (x+h, y+h*m1)
        
        // Calculate the new values of x and y
        float y_new = y + (m1 + m2) * h / 2;
        
        // Print each iteration's result
        printf("%d\t\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", i, x, y, m1, m2, y_new);
        
        // Update x and y for the next iteration
        x = x + h;
        y = y_new;
    }
    
    // Output the final result
    printf("\nThe value of y at x=%.2f is %.4f\n", x, y);
    printf("Program By: KUSHAL DHAKAL\n");
    
    return 0;
}

