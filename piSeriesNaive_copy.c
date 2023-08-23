#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time_used;
    int n = 10e6;
    int thread_count = omp_get_num_procs();
    int block_size = 128;
    if (argc == 3) {
        block_size = strtol(argv[1], NULL, 10);
        thread_count = strtol(argv[2], NULL, 10);
    }
    printf("threads = %d\n", thread_count);
    printf("block_size = %d\n", block_size);
    
    double sum = 0.0;
    start = clock(); // Registrar el tiempo de inicio
    #pragma omp parallel for num_threads(thread_count) schedule(guided, block_size) reduction(+:sum) private(factor)
    for (int k = 0; k < n; k++) {
        double factor = (k % 2 == 0) ? 1.0 : -1.0;
        sum += factor / (2.0 * k + 1.0);
    }
    double pi_approx = 4.0 * sum;
    end = clock(); // Registrar el tiempo al final
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);
    printf("pi_approx = %24.16e\n", pi_approx);
}
