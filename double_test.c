#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

    printf("Bigger than or equal result: %d, consumed cycles: %ld\n", c,
           after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = a <= b;
    uint64_t after = ckb_current_cycles();

    printf("Less than or equal result: %d, consumed cycles: %ld\n", c,
           after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = a != b;
    uint64_t after = ckb_current_cycles();

    printf("Not equal result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = fpclassify(a);
    uint64_t after = ckb_current_cycles();

    printf("fpclassify result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = isinf(a);
    uint64_t after = ckb_current_cycles();

    printf("isinf result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = isnan(a);
    uint64_t after = ckb_current_cycles();

    printf("isnan result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = isnormal(a);
    uint64_t after = ckb_current_cycles();

    printf("isnormal result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = isfinite(a);
    uint64_t after = ckb_current_cycles();

    printf("isfinite result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    int c = signbit(a);
    uint64_t after = ckb_current_cycles();

    printf("signbit result: %d, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = acos(a);
    uint64_t after = ckb_current_cycles();

    printf("acos result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = acosh(a);
    uint64_t after = ckb_current_cycles();

    printf("acosh result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = asin(a);
    uint64_t after = ckb_current_cycles();

    printf("asin result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = asinh(a);
    uint64_t after = ckb_current_cycles();

    printf("asinh result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = atan(a);
    uint64_t after = ckb_current_cycles();

    printf("atan result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = atan2(a, b);
    uint64_t after = ckb_current_cycles();

    printf("atan2 result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = atanh(a);
    uint64_t after = ckb_current_cycles();

    printf("atanh result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = cbrt(a);
    uint64_t after = ckb_current_cycles();

    printf("cbrt result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = ceil(a);
    uint64_t after = ckb_current_cycles();

    printf("ceil result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = copysign(a, b);
    uint64_t after = ckb_current_cycles();

    printf("copysign result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = cos(a);
    uint64_t after = ckb_current_cycles();

    printf("cos result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = cosh(a);
    uint64_t after = ckb_current_cycles();

    printf("cosh result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = erf(a);
    uint64_t after = ckb_current_cycles();

    printf("erf result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = erfc(a);
    uint64_t after = ckb_current_cycles();

    printf("erfc result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = exp(a);
    uint64_t after = ckb_current_cycles();

    printf("exp result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = exp2(a);
    uint64_t after = ckb_current_cycles();

    printf("exp2 result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = expm1(a);
    uint64_t after = ckb_current_cycles();

    printf("expm1 result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = fabs(a);
    uint64_t after = ckb_current_cycles();

    printf("fabs result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = fdim(a, b);
    uint64_t after = ckb_current_cycles();

    printf("fdim result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = floor(a);
    uint64_t after = ckb_current_cycles();

    printf("floor result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = fma(a, b, a);
    uint64_t after = ckb_current_cycles();

    printf("fma result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = fmax(a, b);
    uint64_t after = ckb_current_cycles();

    printf("fmax result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = fmin(a, b);
    uint64_t after = ckb_current_cycles();

    printf("fmin result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = fmod(a, b);
    uint64_t after = ckb_current_cycles();

    printf("fmod result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = hypot(a, b);
    uint64_t after = ckb_current_cycles();

    printf("hypot result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = ilogb(a);
    uint64_t after = ckb_current_cycles();

    printf("ilogb result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = lgamma(a);
    uint64_t after = ckb_current_cycles();

    printf("lgamma result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = log(a);
    uint64_t after = ckb_current_cycles();

    printf("log result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = log10(a);
    uint64_t after = ckb_current_cycles();

    printf("log10 result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = log1p(a);
    uint64_t after = ckb_current_cycles();

    printf("log1p result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = log2(a);
    uint64_t after = ckb_current_cycles();

    printf("log2 result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = logb(a);
    uint64_t after = ckb_current_cycles();

    printf("logb result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = nearbyint(a);
    uint64_t after = ckb_current_cycles();

    printf("nearbyint result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = nextafter(a, b);
    uint64_t after = ckb_current_cycles();

    printf("nextafter result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = nexttoward(a, b);
    uint64_t after = ckb_current_cycles();

    printf("nexttoward result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = pow(a, b);
    uint64_t after = ckb_current_cycles();

    printf("pow result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = remainder(a, b);
    uint64_t after = ckb_current_cycles();

    printf("remainder result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = rint(a);
    uint64_t after = ckb_current_cycles();

    printf("rint result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = round(a);
    uint64_t after = ckb_current_cycles();

    printf("round result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = scalbn(a, 13);
    uint64_t after = ckb_current_cycles();

    printf("scalbn result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = sin(a);
    uint64_t after = ckb_current_cycles();

    printf("sin result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = sinh(a);
    uint64_t after = ckb_current_cycles();

    printf("sinh result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = sqrt(a);
    uint64_t after = ckb_current_cycles();

    printf("sqrt result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = tan(a);
    uint64_t after = ckb_current_cycles();

    printf("tan result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = tanh(a);
    uint64_t after = ckb_current_cycles();

    printf("tanh result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = tgamma(a);
    uint64_t after = ckb_current_cycles();

    printf("tgamma result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  {
    uint64_t before = ckb_current_cycles();
    double c = trunc(a);
    uint64_t after = ckb_current_cycles();

    printf("trunc result: %lf, consumed cycles: %ld\n", c, after - before);
  }

  return 0;
}
