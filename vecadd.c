#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <openacc.h>

int main(int argc, char *argv[])
{

    // Size of vectors
    int n = 10000;

    double time_spent;
    clock_t begin, end;

    // Input vectors
    double *restrict a;
    double *restrict b;
    // Output vector
    double *restrict c;

    // Size, in bytes, of each vector
    size_t bytes = n * sizeof(double);

    // Allocate memory for each vector
    a = (double *)malloc(bytes);
    b = (double *)malloc(bytes);
    c = (double *)malloc(bytes);

    // Initialize content of input vectors, vector a[i] = sin(i)^2 vector b[i] = cos(i)^2
    int i;

    begin = clock();

#pragma acc data copyin(a [0:n], b [0:n]), copy(c [0:n])
    for (i = 0; i < n; i++)
    {
        a[i] = sin(i) * sin(i);
        b[i] = cos(i) * cos(i);
    }

// sum component wise and save result into vector c
#pragma acc kernels
    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }

    // Sum up vector c and print result divided by n, this should equal 1 within error
    double sum = 0.0;
#pragma acc kernels
    for (i = 0; i < n; i++)
    {
        sum += c[i];
    }
    sum = sum / n;
    printf("final result: %f\n", sum);

    // Release memory
    free(a);
    free(b);
    free(c);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("OpenAAC tempo: %f segundos\n", time_spent);

    return 0;
}