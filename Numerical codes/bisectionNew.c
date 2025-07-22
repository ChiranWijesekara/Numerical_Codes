#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 3) - 0.165 * pow(x, 2) + 3.99e-4;
}

double relative_error(double xold, double xnew) {
    return fabs((xnew - xold) / xnew);
}

int sig_digit(double tolerance) {
    if (tolerance <= 0) return 0;
    return (int)(2 - log10(2 * tolerance));
}

double bisection(double x_1, double x_2, double settolerance, int max_iterations) {
    double tolerance = 1.0; // Initialize to a large value
    int cal_iterations = 0;
    double oldmid = 0.0;
    double newmid = 0.0;

    if ((f(x_1) * f(x_2)) > 0) return -1;

    printf("Iter\tX1\t\tX2\t\tXmid\t\tError%%\t\tSigDigits\n");
    
    do {
        cal_iterations++;
        newmid = (x_1 + x_2) / 2.0;
        
        // Calculate error only after first iteration
        if (cal_iterations > 1) {
            tolerance = relative_error(oldmid, newmid);
        }
        
        // Print current iteration information
        printf("%d\t%.6f\t%.6f\t%.6f\t", cal_iterations, x_1, x_2, newmid);
        if (cal_iterations > 1) {
            printf("%.6f\t%d\n", tolerance * 100, sig_digit(tolerance));
        } else {
            printf("-\t\t-\n");
        }

        // Update interval
        if (f(x_1) * f(newmid) < 0) {
            x_2 = newmid;
        } else {
            x_1 = newmid;
        }

        oldmid = newmid;
    } while (tolerance > settolerance && cal_iterations < max_iterations);

    return newmid;
}

int main() {
    double x_1 = 0.0;
    double x_2 = 0.11;
    double settolerance = 0.0001;
    int max_iterations = 20;  // Increased for better convergence
    
    double root = bisection(x_1, x_2, settolerance, max_iterations);
    
    if (root != -1) {
        printf("\nRoot found at x = %.6f\n", root);
    } else {
        printf("\nNo root found in the given interval or maximum iterations reached.\n");
    }
    
    return 0;
}