#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 256

#define OPERATION_INVOKE(validateStatus, result, operationInvoke, ...) \
  if (*validateStatus != ERROR && operationInvoke)                     \
  result = (*operationInvoke)(__VA_ARGS__)

typedef enum { BINARY, UNARY, BRACKET } operationType;

typedef enum {
  SIN,
  COS,
  TAN,
  ASIN,
  ACOS,
  ATAN,
  SQRT,
  FACTORIAL,
  LOG,
  LN,
  MOD,
  SUM,
  SUB,
  UNARY_SUB,
  MUL,
  DIV,
  POW,
  OPEN_BRACKET,
  CLOSE_BRACKET
} operations;

typedef struct srtingStruct {
  char* chr;
  char* end;
} string;

typedef struct operationStruct {
  int index;
  void* invoke;
  operationType type;
  const char* name;
  int priority;
} operation;

typedef union {
  double num;
  operation* operator;
} element;

typedef enum { OPERATIONS, NUMBERS } stackType;

typedef enum { OK, ERROR, STACK_EMPTY, STACK_FULL, STACK_CREATED } status;

typedef double (*binaryOperation)(double, double);
typedef double (*unaryOperation)(double);

typedef struct stackStruct {
  stackType type;
  element* data;
  element* top;
} stack;

double factorial(double n);
double sum(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);
double unarySub(double x);

#define operationsCount 19

static const operation operationsList[operationsCount] = {
    [SIN] = {SIN, sin, UNARY, "sin", 3},
    [COS] = {COS, cos, UNARY, "cos", 3},
    [TAN] = {TAN, tan, UNARY, "tan", 3},
    [ASIN] = {ASIN, asin, UNARY, "asin", 3},
    [ACOS] = {ACOS, acos, UNARY, "acos", 3},
    [ATAN] = {ATAN, atan, UNARY, "atan", 3},
    [SQRT] = {SQRT, sqrt, UNARY, "sqrt", 3},
    [FACTORIAL] = {FACTORIAL, factorial, UNARY, "sqrt", 4},
    [LOG] = {LOG, log2, UNARY, "log", 3},
    [LN] = {LN, log, UNARY, "ln", 3},
    [MOD] = {MOD, fmod, BINARY, "%", 2},
    [SUM] = {SUM, sum, BINARY, "+", 1},
    [SUB] = {SUB, sub, BINARY, "-", 1},
    [UNARY_SUB] = {UNARY_SUB, unarySub, UNARY, "~", 3},
    [MUL] = {MUL, mul, BINARY, "*", 2},
    [DIV] = {DIV, divide, BINARY, "/", 2},
    [POW] = {POW, pow, BINARY, "^", 4},
    [OPEN_BRACKET] = {OPEN_BRACKET, NULL, BRACKET, "(", 5},
    [CLOSE_BRACKET] = {CLOSE_BRACKET, NULL, BRACKET, ")", 5},
};

typedef struct constant {
  double value;
  const char* name;
  int nameLen;
} constant;

#define constantsCount 2

static const constant constantList[constantsCount] = {
    {M_PI, "p", 1},
    {M_E, "e", 1},
};

status createStack(stackType type, stack* stck);
status removeStack(stack* stck);
status pushStack(stack* s, element elem);
element popStack(stack* stck, status* resCode);

bool isDigit(string* str, element* elem);
bool isOperator(string* str, element* currentOperation, status* validateStatus);
bool isSameString(char* str1, const char* str2, int len);

bool isStackEmpty(stack* stck);
bool isStackFull(stack* stck);
bool isLowerPriority(stack* operationStack, element* currentElement);
bool isBracket(string* currentString, element* currentElement);
bool isOpenBracket(element* currentElement);
bool isCloseBracket(element* currentElement);
bool isEqualX(string* currentString);
bool isConstant(string* currentString, element* currentElement);
void bracketsHandler(stack* operationStack, stack* numberStack,
                     element currentElement, status* validateStatus);

double getResultOfExpression(const char* chr, int* status, double x);

string getString(const char* chr);
double calculate(string currentString, status* validateStatus, double x);

#endif  // CALCULATOR_H
