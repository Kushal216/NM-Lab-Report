#include <stdio.h>
int i,j;
// Function to calculate factorial
int factorial(int n)
{
    int fact = 1;
    for (i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to implement Newton's Forward Difference Interpolation
double newtonForward(double x[], double y[][10], int n, double xp)
{
    double h = x[1] - x[0];
    double u = (xp - x[0]) / h;
    double yp = y[0][0];
    double term;

    for ( i = 1; i < n; i++)
    {
        term = y[0][i];
        for (j = 0; j < i; j++)
        {
            term *= (u - j);
        }
        term /= factorial(i);
        yp += term;
    }
    return yp;
}

int main()
{
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("Error: Number of data points must be greater than 0.\n");
        return 1;
    }

    double x[n], y[n][n];  // Updated array size

    printf("\nEnter data points:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d, y%d: ", i, i);
        scanf("%lf%lf", &x[i], &y[i][0]);
    }

    // Forward difference table
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    double xp;
    printf("Enter interpolation point x: ");
    scanf("%lf", &xp);

    double yp = newtonForward(x, y, n, xp);

    // Display forward difference table
    printf("\nForward Difference Table:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("%.2lf", x[i]);
        for (j = 0; j < n - i; j++)
        {
            printf("\t%.4lf", y[i][j]);
        }
        printf("\n");
    }

    printf("\nInterpolated value at x = %.2lf is y = %.4lf\n", xp, yp);

    // Print required information
    printf("\nProgram By: KUSHAL DHAKAL\n");
    return 0;
}

