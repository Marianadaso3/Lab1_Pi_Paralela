#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 10000;
    if (argc > 1) {
        n = strtol(argv[1], NULL,10);
    }
    double factor = 1.0;
    double sum = 0.0;
    for (int k = 0; k < n; k++) {
        sum += factor/(2*k+1);
        factor = - factor;
    }
    double pi_approx = 4.0*sum;

    printf("pi_approx = %24.16e\n", pi_approx);
}