#include <stdio.h>
#include <math.h>

#define SIZE 3
#define TOLERANCE 0.0001
#define MAX_ITERATIONS 100

int main() {
    float a[SIZE][SIZE], b[SIZE], x[SIZE], x_new[SIZE];
    int i, j, iterations = 0;
    float error;

    // Input coefficients
    printf("Enter the coefficients of the matrix A (3x3):\n");
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Input constants (right-hand side)
    printf("Enter the constants (b vector):\n");
    for(i = 0; i < SIZE; i++) {
        scanf("%f", &b[i]);
    }

    // Initial guesses
    printf("Enter initial guesses:\n");
    for(i = 0; i < SIZE; i++) {
        scanf("%f", &x[i]);
    }

    do {
        iterations++;
        for(i = 0; i < SIZE; i++) {
            x_new[i] = b[i];
            for(j = 0; j < SIZE; j++) {
                if(i != j)
                    x_new[i] -= a[i][j] * x[j];
            }
            x_new[i] /= a[i][i];
        }

        // Calculate error
        error = 0;
        for(i = 0; i < SIZE; i++) {
            error += fabs(x_new[i] - x[i]);
            x[i] = x_new[i];
        }

        printf("Iteration %d: ", iterations);
        for(i = 0; i < SIZE; i++) {
            printf("x[%d] = %.6f\t", i+1, x[i]);
        }
        printf("\n");

    } while(error > TOLERANCE && iterations < MAX_ITERATIONS);

    printf("\nSolution after %d iterations:\n", iterations);
    for(i = 0; i < SIZE; i++) {
        printf("x[%d] = %.6f\n", i+1, x[i]);
    }

    return 0;
}
