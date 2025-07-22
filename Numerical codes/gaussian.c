#include <stdio.h>

#define N 3  // number of variables

void gaussianElimination(double a[N][N + 1]) {
    int i, j, k;
    double factor;
    // Forward Elimination
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (a[i][i] == 0) {
                printf("Error: Division by zero.\n");
                return;
            }

            factor = a[j][i] / a[i][i];

            for (k = i; k <= N; k++) {
                a[j][k] = a[j][k] - factor * a[i][k];
            }
        }
    }

    // Back Substitution
    double x[N];
    for (i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Output
    printf("\nSolution:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %.6f\n", i + 1, x[i]);
    }
}

int main() {
    // Augmented matrix [A | b]
    double a[N][N + 1] = {
        {25, 5, 1, 106.8},
        {64, 8, 1, 177.2},
        {144, 12, 1, 279.2}
    };

    gaussianElimination(a);

    return 0;
}
