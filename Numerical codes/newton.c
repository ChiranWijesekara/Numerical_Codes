#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x,3)-0.165*pow(x,2)+3.993e-4;
}

double f_prime(double x){
    return 3*pow(x,2) - 0.33*x;
}

double relative_error(double old_value, double new_value) {
    return fabs((new_value - old_value) / new_value);
}

double newton(double x,double settolerance) {
    double oldx = x;
    double tolerance = 1.0; 
    
    while(tolerance > settolerance) {

        double newx = x - (f(x)/f_prime(x));
        
        printf("Current x: %.10f\n", newx);
        
        tolerance = relative_error(oldx, newx);
        printf("Current tolerance: %.10f\n", tolerance);
        
        
        oldx = newx;
        x = newx;

        if(f_prime(x) == 0.0){
            printf("Derivative is zero at x = %.10f, cannot continue.\n", x);
            return -1; 
        }

        printf("....................................................................\n");
    }

    printf("Root found within tolerance %.10f at x = %.10f\n", tolerance, x);
    return x;
}

int main() {
    double x = 0.05; 
    double settolerance = 0.0001;

    double root = newton(x, settolerance);
    if (root != -1) {
        printf("Root found at x = %.10f\n", root);
        printf("Function value at root: %.10f\n", f(root));
    } else {
        printf("No root found.\n");
    }

    return 0;
}