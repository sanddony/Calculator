#include "calculator.h"

string getString(const char* chr) {
  string result;
  int len = strlen(chr);
  if (chr) {
    result.chr = malloc(len + 1);
    result.chr[len] = '\0';

    strcpy(result.chr, chr);
    result.end = result.chr + len;
  }
  return result;
}

// int main() {
//     status curr = OK;
//     // string str = getString("sin(cos(3*3-2))");
//     // string str = getString("2*3-2+(1+(3*3)+3)");
//     string str = getString("3+π");
//     // string str = getString("sin(3*3)-2");
//     // bool res = isSameString(operationsList[1].name, str.chr, 3);
//     double res = calculate(str, &curr,0);
//     printf("res = %f\n", res);
//     printf("res = %f\n", (3*3+(3*3))+((13+2)));
//     return 0;
// }

double getResultOfExpression(const char* chr, int* statusExternal, double x) {
  return calculate(getString(chr), (status*)statusExternal, x);
}

void operationInvoker(status* validateStatus, stack* operationStack,
                      stack* numberStack) {
  double result = 0;
  element currentOperation = popStack(operationStack, validateStatus);
  if (currentOperation.operator->type == UNARY) {
    OPERATION_INVOKE(validateStatus, result,
                     (unaryOperation)(currentOperation.operator->invoke),
                     popStack(numberStack, validateStatus).num);
    pushStack(numberStack, (element)result);
  } else if (currentOperation.operator->type == BINARY) {
    double secondOperand = popStack(numberStack, validateStatus).num;
    double firstOperand = popStack(numberStack, validateStatus).num;
    OPERATION_INVOKE(validateStatus, result,
                     (binaryOperation)(currentOperation.operator->invoke),
                     firstOperand, secondOperand);
    pushStack(numberStack, (element)result);
  } else {
  }
}

void bracketsHandler(stack* operationStack, stack* numberStack,
                     element currentElement, status* validateStatus) {
  if (isOpenBracket(&currentElement)) {
    *validateStatus = pushStack(operationStack, currentElement);
  } else {
    while (!isOpenBracket(operationStack->top)) {
      operationInvoker(validateStatus, operationStack, numberStack);
    }
    popStack(operationStack, validateStatus);
  }
}

double calculate(string currentString, status* validateStatus, double x) {
  stack operationStack;
  createStack(OPERATIONS, &operationStack);

  stack numberStack;
  createStack(NUMBERS, &numberStack);

  element currentElement;

  while (*(currentString.chr) != *(currentString.end)) {
    if (isEqualX(&currentString)) {
      *validateStatus = pushStack(&numberStack, (element)x);
      currentString.chr++;
    } else if (isConstant(&currentString, &currentElement)) {
      *validateStatus = pushStack(&numberStack, currentElement);
    } else if (isDigit(&currentString, &currentElement)) {
      *validateStatus = pushStack(&numberStack, currentElement);
    } else if (isBracket(&currentString, &currentElement)) {
      bracketsHandler(&operationStack, &numberStack, currentElement,
                      validateStatus);
    } else if (isOperator(&currentString, &currentElement, validateStatus)) {
      if (!isStackEmpty(&operationStack) &&
          !isOpenBracket(operationStack.top) &&
          !isLowerPriority(&operationStack, &currentElement)) {
        operationInvoker(validateStatus, &operationStack, &numberStack);
      }
      *validateStatus = pushStack(&operationStack, currentElement);
    }
  }

  while (!isStackEmpty(&operationStack) && !isStackEmpty(&numberStack)) {
    if (isBracket(&currentString, &currentElement)) {
      bracketsHandler(&operationStack, &numberStack, currentElement,
                      validateStatus);
    } else {
      operationInvoker(validateStatus, &operationStack, &numberStack);
    }
  }
  currentElement = popStack(&numberStack, validateStatus);

  removeStack(&operationStack);
  removeStack(&numberStack);

  return currentElement.num;
}
