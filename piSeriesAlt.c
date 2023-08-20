#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time_used;
    int n = 10e6;
    int thread_count = 4;
    int block_size = 16;
    if (argc == 3) {
        n = strtol(argv[1], NULL,10);
        thread_count = strtol(argv[2], NULL, 10);
    }
    printf("threads = %d\n", thread_count);
    double factor = 1.0;
    double sum = 0.0;
    start = clock(); // Registrar el tiempo de inicio
    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (int k = 0; k < n; k++) {
        if (k % 2 == 0){
            sum += 1.0/(2*k+1);
        }
        else {
            sum += -1.0/(2*k+1);
        }
    }
    double pi_approx = 4.0*(sum);
    end = clock(); // Registrar el tiempo al final
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);
    
    printf("pi_approx = %24.16e\n", pi_approx);
}