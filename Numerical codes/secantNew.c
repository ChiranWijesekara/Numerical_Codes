#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x,3) - 0.165*pow(x,2) + 3.993e-4;
}

int sig_digit(double tolerance){
    if (tolerance <= 0) return 0;
    return (int)(2 - log10(2 * tolerance));
}
double secant(double guess1, double guess2, double settolerence, int iterations) {
    double newx, tolerance;
    int i;
    
    printf("Iter\tGuess1\t\tGuess2\t\tNewX\t\tTolerance (%%)\tSig.Digit\n");
    
    for (i = 0; i < iterations; i++) {
        newx = guess2 - (f(guess2) * (guess2 - guess1)) / (f(guess2) - f(guess1));
        tolerance = fabs((newx - guess2) / newx) * 100;
        
        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%d\n", i+1, guess1, guess2, newx, tolerance, sig_digit(tolerance));
        
        if (fabs(tolerance) < settolerence) {
            return newx;
        }
        
        guess1 = guess2;
        guess2 = newx;
    }
    
    return -1; // Return -1 if no root found within iterations
}

int main() {
    double x = 0.02;
    double y = 0.05;
    double settolerence = 0.001;
    int iterations = 100;

    double root = secant(x, y, settolerence, iterations);
    if (root != -1) {
        printf("\nRoot found at x = %.6f\n", root);
        printf("f(root) : %.100f \n",f(root));
    } else {
        printf("\nNo root found in the given interval or maximum iterations reached.\n");
    }
    
    return 0;
}