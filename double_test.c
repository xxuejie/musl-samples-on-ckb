#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ckb_syscalls.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return 1;
  }

  double a = atof(argv[0]);
  double b = atof(argv[1]);

  {
    uint64_t before = ckb_current_cycles();
    double c = a + b;
    uint64_t after = ckb_current_cycles();

    printf("Add result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = a - b;
    uint64_t after = ckb_current_cycles();

    printf("Sub result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = a * b;
    uint64_t after = ckb_current_cycles();

    printf("Mul result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = a / b;
    uint64_t after = ckb_current_cycles();

    printf("Div result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = a > b;
    uint64_t after = ckb_current_cycles();

    printf("Bigger than result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = a < b;
    uint64_t after = ckb_current_cycles();

    printf("Less than result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = a >= b;
    uint64_t after = ckb_current_cycles();

    printf("Bigger than or equal result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = a <= b;
    uint64_t after = ckb_current_cycles();

    printf("Less than or equal result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = ceil(a);
    uint64_t after = ckb_current_cycles();

    printf("Ceil result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = floor(a);
    uint64_t after = ckb_current_cycles();

    printf("Floor result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = sqrt(a);
    uint64_t after = ckb_current_cycles();

    printf("Sqrt result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = pow(a, b);
    uint64_t after = ckb_current_cycles();

    printf("Pow result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  return 0;
}
