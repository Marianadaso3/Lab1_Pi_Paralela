#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int num_threads = 0;
    if (argc > 1) {
        num_threads = atoi(argv[1]);  
    }

    //seccion paralela
    #pragma omp parallel num_threads(num_threads)
    {
        int thread_num = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        if (thread_num % 2 == 1) {
            printf("Feliz cumpleañoso %d!\n", total_threads);
        }
        else {
            printf("Saludos del hilo %d\n", thread_num);
        }
    }

    return 0;
}
