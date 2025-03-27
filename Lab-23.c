#include <stdio.h>
#include <math.h>
#define MAX 10
#define E 0.0001
#define N 100

void inputMatrix(int n, float a[MAX][MAX]) {
    int i, j;
    printf("Enter %dx%d elements for the augmented matrix:\n", n, n + 1);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + 1; j++)
            scanf("%f", &a[i][j]);
}

void initializeX0(int n, float x0[MAX]) {
    int i;
    for (i = 1; i <= n; i++)
        x0[i] = 0;
}

void gaussSeidel(int n, float a[MAX][MAX], float x[MAX], float x0[MAX]) {
    int i, j, k;
    float sum1, sum2;
    
    printf("\nIteration Table:\n");
    printf("\n");
    printf("Iter\t");
    for (i = 1; i <= n; i++) {
        printf("x[%d]\t", i);
    }
    printf("Error\n\n");

    for (k = 1; k <= N; k++) {
        float max_error = 0.0;
        
        for (i = 1; i <= n; i++) {
            sum1 = sum2 = 0;
            for (j = 1; j <= i - 1; j++)
                sum1 += a[i][j] * x[j];
            for (j = i + 1; j <= n; j++)
                sum2 += a[i][j] * x0[j];
            
            x[i] = (-sum1 - sum2 + a[i][n + 1]) / a[i][i];
            float error = fabs(x[i] - x0[i]);
            if (error > max_error)
                max_error = error;
        }
        
        printf("%d\t", k);
        for (i = 1; i <= n; i++) {
            printf("%.4f\t", x[i]);
        }
        printf("%.6f\n", max_error);

        if (max_error < E)
            break;

        for (i = 1; i <= n; i++) {
            x0[i] = x[i];
        }
    }
    
    printf("\n");
    if (k == N + 1)
        printf("Maximum number of iterations exceeded.\n");
    else {
        printf("The solution set is:\n");
        for (i = 1; i <= n; i++)
            printf("x[%d] = %.6f\n", i, x[i]);
    }
    printf("The number of iterations: %d\n", k);
    printf("Program By: KUSHAL DHAKAL\n");
}

int main() {
    int n, i;
    float a[MAX][MAX], x[MAX], x0[MAX];
    
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    
    inputMatrix(n, a);
    initializeX0(n, x0);
    
    gaussSeidel(n, a, x, x0);
    
    return 0;
}

