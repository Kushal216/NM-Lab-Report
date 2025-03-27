//18.	Write a C program to solve ordinary differential equation using 4th Order Runge Kutta method.
#include <stdio.h>
#include <math.h>

#define f(x, y) ((x) * (x) + (y) * (y)) // Function: x^2 + y^2

void rungeKutta(float x, float y, float h, float xp) {
    int i, n = (int)((xp - x) / h);
    float m1, m2, m3, m4;
    printf("The Equation used for calcuation is:\nx^2 + y^2\n");
    printf("\nIterative Table:\n\n");
    printf("Iteration\tx\ty\tm1\tm2\tm3\tm4\n");
    
    for (i = 1; i <= n; i++) {
        m1 = f(x, y);
        m2 = f(x + h / 2, y + (m1 * h / 2));
        m3 = f(x + h / 2, y + (m2 * h / 2));
        m4 = f(x + h, y + (m3 * h));
        
        printf("%d\t\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", i, x, y, m1, m2, m3, m4);
        
        x = x + h;
        y = y + ((m1 + 2 * m2 + 2 * m3 + m4) * h) / 6;
    }
    
    printf("\nThe value of y at x=%.2f is %.4f\n", x, y);
    printf("\nProgram By: KUSHAL DHAKAL\n");
}

int main() {
    float x, y, h, xp;
    
    printf("Enter initial values of x and y: ");
    scanf("%f%f", &x, &y);
    printf("Enter x-value at which y is required: ");
    scanf("%f", &xp);
    printf("Enter step-size: ");
    scanf("%f", &h);
    
    rungeKutta(x, y, h, xp);
    
    return 0;
}

