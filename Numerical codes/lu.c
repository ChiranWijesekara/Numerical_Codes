#include<stdio.h>
#include<math.h>
#define N 3


void printmatrix(double M[N][N]){
    for (int i = 0; i < N; i++){
        printf("      |");
        for (int j = 0; j < N; j++)
        {
            printf(" %.5f  ",M[i][j]);
        }
        printf("|\n");
        
    }
    
}

void LUDecomposition(double A[N][N],double L[N][N],double U[N][N]){

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(i == j){
                L[i][i] = 1;
            }else{
                L[i][j] = 0;
            }

            U[i][j] = A[i][j];
        }
        
    }
    

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double factor = U[j][i]/U[i][i];

            L[j][i] = factor;
            
            for (int k = i; k < N; k++) {
                U[j][k] = U[j][k] - factor * U[i][k];
            }

            
        }
        
    }
    

}


void forwardSubstitution(double L[N][N], double b[N], double Y[N]) {
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * Y[j];
        Y[i] = (b[i] - sum) / L[i][i];
    }
}

void backwardSubstitution(double U[N][N], double Y[N], double X[N]) {
    
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++)
            sum += U[i][j] * X[j];
        X[i] = (Y[i] - sum) / U[i][i];
    }
}

void print1D(double X[N]){

    printf("        | ");
    for (int i = 0; i < N; i++)
    {
        printf("%7.4f  ",X[i]);
    }
    printf("| \n\n");

    
}


int main (){
        double A[N][N] = {
            {1,1,-1},
            {1,-2,3},
            {2,3,1}
        };
        double L[N][N], U[N][N];

        double b[N] = {4,-6,7};
        double Y[N] = {0};
        double X[N] = {0};

        printf("    A matrix : \n\n");
        printmatrix(A);
        printf("\n\n");
        LUDecomposition(A,L,U);
        printf("    L matrix : \n\n");
        printmatrix(L);
        printf("\n\n");
        printf("    U matrix : \n\n");
        printmatrix(U);
        printf("\n\n");
        forwardSubstitution(L,b,Y);
        printf("    Y Matrix : \n");
        print1D(Y);
        backwardSubstitution(U,Y,X);
        printf("    X Matrix : \n");
        print1D(X);

}