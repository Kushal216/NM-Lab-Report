
#include <stdio.h>
int i;
// Function to compute the first derivative using forward difference
double forward_difference(double x[], double y[], int n, double xp, double h)
{
    for (i = 0; i < n - 1; i++)
    {
        if (x[i] == xp)
        {                                 // Find the closest x value
            return (y[i + 1] - y[i]) / h; // First derivative formula
        }
    }
    return 0.0;
}

int main()
{
    int n;
    double x[100], y[100], xp, h;

    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    // Input x and y values
    printf("Enter x and y values:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i);
        scanf("%lf", &y[i]);
    }

    // Input the point where derivative is needed
    printf("Enter x value to calculate derivative: ");
    scanf("%lf", &xp);

    // Step size h
    h = x[1] - x[0];

    // Compute the first derivative
    double derivative = forward_difference(x, y, n, xp, h);

    // Output result
    printf("Approximate derivative at x = %lf is f'(x) = %lf\n", xp, derivative);
    printf("Program By: KUSHAL DHAKAL");
    return 0;
}
