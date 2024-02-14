#include "calculator.h"

double factorial(double n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

double unarySub(double x) { return -x; }

double sum(double a, double b) { return a + b; }

double sub(double a, double b) { return a - b; }

double mul(double a, double b) { return a * b; }

double divide(double a, double b) { return a / b; }
