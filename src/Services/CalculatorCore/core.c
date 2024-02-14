#include "calculator.h"

double calculateExpression(const char* expression, int* validateStatus,
                           double x) {
  return getResultOfExpression(expression, validateStatus, x);
}