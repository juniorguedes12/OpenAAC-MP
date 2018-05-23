#include <stdio.h>
#include <time.h>

#define N 200000000

#define vl 1024

int main(void)
{

  double pi = 0.0f;
  long long i;

  double time_spent;
  clock_t begin, end;

  begin = clock();

 
#pragma acc kernels
  for (i = 0; i < N; i++)
  {
    double t = (double)((i + 0.5) / N);
    pi += 4.0 / (1.0 + t * t);
  }

  printf("pi=%11.10f\n", pi / N);

  end = clock();

  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("tempo: %f segundos\n", time_spent);

  return 0;
}