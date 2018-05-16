/*
 *  Copyright 2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

//pgcc -acc -Minfo=accel laplace.c

#include <math.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <openacc.h>

#define NN 1024
#define NM 1024

double A[NN][NM];
double Anew[NN][NM];

int main(int argc, char **argv)
{
    const int n = NN;
    const int m = NM;
    const int iter_max = 1000;

    const double tol = 1.0e-6;
    double error = 1.0;

    double time_spent;
    clock_t begin, end;

    memset(A, 0, n * m * sizeof(double));
    memset(Anew, 0, n * m * sizeof(double));

    for (int j = 0; j < n; j++)
    {
        A[j][0] = 1.0;
        Anew[j][0] = 1.0;
    }

    printf("Jacobi relaxation Calculation: %d x %d mesh\n", n, m);

    begin = clock();
    int iter = 0;

    // acc_set_device_num(0,acc_device_nvidia);
    //printf("%d",acc_get_num_devices(acc_device_nvidia));
#pragma acc data copyin(A), copy(Anew)
    while (error > tol && iter < iter_max)
    {
        error = 0.0;

        //#pragma omp parallel for shared(m, n, Anew, A)
#pragma acc kernels
        for (int j = 1; j < n - 1; j++)
        {
            for (int i = 1; i < m - 1; i++)
            {
                Anew[j][i] = 0.25 * (A[j][i + 1] + A[j][i - 1] + A[j - 1][i] + A[j + 1][i]);
                error = fmax(error, fabs(Anew[j][i] - A[j][i]));
            }
        }

        //#pragma omp parallel for shared(m, n, Anew, A)
#pragma acc kernels
        for (int j = 1; j < n - 1; j++)
        {
            for (int i = 1; i < m - 1; i++)
            {
                A[j][i] = Anew[j][i];
            }
        }

        if (iter % 100 == 0)
            printf("%5d, %0.6f\n", iter, error);

        iter++;
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf(" total: %f s\n", time_spent);
}