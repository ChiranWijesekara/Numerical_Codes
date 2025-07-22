#include<stdio.h>
#include<math.h>
#define N 3

void Cholesky(double A[N][N],double L[N][N],double LTranspose[N][N]){

    for (int i = 0; i < N; i++){
        for (int j = 0; j <= i; j++){
            double sum = 0;
            if(i == j){

                for (int k = 0; k < j; k++){
                    sum += L[j][k]*L[j][k];
                }

                L[i][i] = sqrt(A[i][i]-sum);
                

            }else{

                for (int k = 0; k < j; k++){
                    sum += L[i][k]*L[j][k];
                }

                L[i][j] = (A[i][j] - sum)/L[j][j];
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

void backwardSubstitution(double LTranspose[N][N], double Y[N], double X[N]) {
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++)
            sum += LTranspose[i][j] * X[j];
        X[i] = (Y[i] - sum) / LTranspose[i][i];
    }
}

void Transpose(double L[N][N],double LTranspose[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            LTranspose[j][i] = L[i][j];
        }
    }
    
}


void printMatrix(double M[N][N]){
    for (int i = 0; i < N; i++)
    {
        printf("        | ");
        for (int j = 0; j < N; j++)
        {
            printf("%7.4f  ",M[i][j]);
        }
        printf(" |\n");
        
    }

    printf("\n\n");
    
}

void print1D(double X[N]){

    printf("        | ");
    for (int i = 0; i < N; i++)
    {
        printf("%7.4f  ",X[i]);
    }
    printf("| \n\n");

    
}

int main(){
    double A[N][N] = {
        {4,2,14},
        {2,17,-5},
        {14,-5,83}
    };

    double L[N][N] = {0};
    double LTranspose[N][N] = {0};
    double b[N] = {14,-101,155};
    double Y[N] = {0};
    double X[N] = {0};

    printf("    A Matrix : \n");
    printMatrix(A);
    Cholesky(A,L,LTranspose);
    printf("    L Matrix : \n");
    printMatrix(L);
    Transpose(L,LTranspose);
    printf("    L Transpose Matrix : \n");
    printMatrix(LTranspose);
    forwardSubstitution(L,b,Y);
    printf("    Y Matrix : \n");
    print1D(Y);
    backwardSubstitution(LTranspose,Y,X);
    printf("    X Matrix : \n");
    print1D(X);
}