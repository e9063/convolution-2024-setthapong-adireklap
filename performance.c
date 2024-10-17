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
    
    double startAt, endAt;

    //sequential
    startAt = omp_get_wtime();
    for(int i = 0 ; i<NR ; i++){
        int tmp = 0;
        for(int j = 0 ; j<NF ; j++){
            tmp += A[i+j] * F[j];
        }
        R[i] = tmp;
    };
    endAt = omp_get_wtime();
    double sequential_time = endAt-startAt;
    //printf("Total time used (sequential) = %f\n", sequential_time);
    free(R);
    
    //parallel
    R = malloc(sizeof(int)*NR);
    startAt = omp_get_wtime();
    omp_set_num_threads(8);
    #pragma omp parallel for schedule(static)
    for(int i = 0 ; i<NR ; i++){
        int tmp = 0;
        for(int j = 0 ; j<NF ; j++){
            tmp += A[i+j] * F[j];
        }
        R[i] = tmp;
    };
    endAt = omp_get_wtime();
    double parallel_time = endAt-startAt;
    //printf("Total time used (parallel) = %f\n", parallel_time);

    double speed_up = sequential_time/parallel_time;
    //printf("Speed up = %f\n", speed_up);

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