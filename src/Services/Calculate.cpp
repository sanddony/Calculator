#include "Calculate.h"

double Calculate::operator()(string &expression) {
  int operation = 0;
  return calculateExpression(expression.c_str(), &operation, 0);
}

double Calculate::operator()(string &expression, double x) {
  int operation = 0;
  return calculateExpression(expression.c_str(), &operation, x);
}
