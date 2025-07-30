#include <stdio.h>
#include <math.h>

#define SIZE 3

void printMatrix(double A[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%10.4f ", A[i][j]);
        }
        printf("\n");
    }
}

void householderTridiagonal(double A[SIZE][SIZE]) {
    for (int k = 0; k < SIZE - 2; k++) {
        double norm = 0.0;
        double v[SIZE] = {0};

        // Compute norm of x = A[k+1 to n][k]
        for (int i = k + 1; i < SIZE; i++) { // i = 1 , 2
            norm += A[i][k] * A[i][k];
        }
        norm = sqrt(norm);

        if (norm == 0.0) continue;

        // Form the Householder vector v
        double sign = (A[k + 1][k] >= 0) ? 1.0 : -1.0;
        v[k + 1] = A[k + 1][k] + sign * norm;
        for (int i = k + 2; i < SIZE; i++) {
            v[i] = A[i][k];
        }

        // Normalize vector v
        double vnorm = 0.0;
        for (int i = k + 1; i < SIZE; i++) {
            vnorm += v[i] * v[i];
        }
        vnorm = sqrt(vnorm);

        //find holde vector
        for (int i = k + 1; i < SIZE; i++) {
            v[i] /= vnorm;
        }

        // Apply the transformation: A = H*A*H
        for (int i = k; i < SIZE; i++) {
            for (int j = k; j < SIZE; j++) {
                double dot = 0.0;
                for (int m = k + 1; m < SIZE; m++) {
                    dot += v[m] * A[m][j];
                }
                for (int m = k + 1; m < SIZE; m++) {
                    A[m][j] -= 2 * v[m] * dot;
                }
            }
        }

        for (int j = k; j < SIZE; j++) {
            for (int i = k; i < SIZE; i++) {
                double dot = 0.0;
                for (int m = k + 1; m < SIZE; m++) {
                    dot += v[m] * A[i][m];
                }
                for (int m = k + 1; m < SIZE; m++) {
                    A[i][m] -= 2 * v[m] * dot;
                }
            }
        }
    }
}

int main() {
    double A[SIZE][SIZE] = {
        {4.0, 1.0, -2.0},
        {1.0, 2.0,  0.0},
        {-2.0, 0.0, 3.0}
    };

    printf("Original Matrix:\n");
    printMatrix(A);

    householderTridiagonal(A);

    printf("\nMatrix after Householder Tridiagonalization:\n");
    printMatrix(A);

    return 0;
}
