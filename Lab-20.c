//20.	Write a C program for solving system of equations using basic Gauss Jordan method.
#include <stdio.h>
#include <math.h>
#define MAX 10

void inputMatrix(int n, float a[MAX][MAX]) {
    int i, j;
    printf("Enter %dx%d elements for the augmented matrix:\n", n, n + 1);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n + 1; j++)
            scanf("%f", &a[i][j]);
}

void printMatrix(int n, float a[MAX][MAX]) {
    int i, j;
    printf("\nCurrent Matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
}

void gaussJordan(int n, float a[MAX][MAX]) {
    int i, j, k;
    float c;
    
    printf("\nPerforming Gauss-Jordan Elimination:\n");
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            if (i != k) {
                c = a[i][k] / a[k][k];
                for (j = k; j <= n + 1; j++)
                    a[i][j] = a[i][j] - c * a[k][j];
            }
        }
        printMatrix(n, a);
    }
    
    printf("\nThe reduced echelon form matrix is:\n");
    for (i = 1; i <= n; i++) {
        a[i][n + 1] /= a[i][i];
        a[i][i] /= a[i][i];
    }
    printMatrix(n, a);
    
    printf("\nThe solution set is:\n");
    for (i = 1; i <= n; i++)
        printf("x[%d] = %.4f\n", i, a[i][n + 1]);
    
    printf("\nProgram By: KUSHAL DHAKAL\n");
}

int main() {
    int n;
    float a[MAX][MAX];
    
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    
    inputMatrix(n, a);
    printMatrix(n, a);
    gaussJordan(n, a);
    
    return 0;
}
