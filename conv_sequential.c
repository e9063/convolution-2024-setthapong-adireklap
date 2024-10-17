#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = NF-1; i >= 0; i--){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    // implement here
    int NR = NA-NF+1;
    int *R = malloc(sizeof(int)*NR);
    for(int i = 0 ; i<NR ; i++){
        int tmp = 0;
        for(int j = 0 ; j<NF ; j++){
            tmp += A[i+j] * F[j];
        }
        R[i] = tmp;
    };

    for(int i = 0 ; i<NR ; i++){
        printf("%d\n", R[i]);
    }

    // ---- free memory ----
    free(F);
    free(A);
    free(R);
    // ---- end free ----
    return 0;
}