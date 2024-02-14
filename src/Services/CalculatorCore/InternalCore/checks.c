#include "calculator.h"

bool isDigit(string* str, element* elem) {
  bool result = false;
  if (*(str->chr) >= 48 && *(str->chr) <= 57 && elem) {
    elem->num = strtod(str->chr, &(str->chr));
    result = true;
  }
  return result;
}

bool isSameString(char* str1, const char* str2, int len) {
  bool result = true;
  int idx = 0;
  while (str1 && str2 && idx < len) {
    if (*(str1 + (idx++)) != *(str2++)) {
      result = false;
      break;
    }
  }
  return result;
}

bool isOperator(string* str, element* currentOperation,
                status* validateStatus) {
  bool result = false;
  int len = 0;
  if (currentOperation && validateStatus) {
    for (int i = 0; i < operationsCount; i++) {
      if (*(str->chr) == operationsList[i].name[0]) {
        len = strlen(operationsList[i].name);
        if (len == 1) {
          (*currentOperation).operator= & operationsList[i];
          result = true;
          break;
        } else if (len > (str->end - str->chr)) {
          *validateStatus = ERROR;
        } else {
          result = isSameString(str->chr, operationsList[i].name, len);

          if (result == false)
            *validateStatus = ERROR;
          else {
            *validateStatus = OK;
            (*currentOperation).operator= & operationsList[i];

            break;
          }
        }
      }
    }
    if (result == true) str->chr += len;
  }
  return result;
}

bool isStackEmpty(stack* stck) { return stck->top + 1 == stck->data; }

bool isStackFull(stack* stck) {
  return stck->top == stck->data + STACK_SIZE - 1;
}

bool isLowerPriority(stack* operationStack, element* currentElement) {
  return operationStack->top->operator->priority<currentElement->
  operator->priority;
}

bool isOpenBracket(element* currentElement) {
  return *(currentElement->operator->name) == '(';
}

bool isCloseBracket(element* currentElement) {
  return *(currentElement->operator->name) == ')';
}

bool isBracket(string* currentString, element* currentElement) {
  bool result = false;
  if (*(currentString->chr) == '(') {
    currentElement->operator= & operationsList[OPEN_BRACKET];
    result = true;
  } else if (*(currentString->chr) == ')') {
    currentElement->operator= & operationsList[CLOSE_BRACKET];
    result = true;
  };
  if (result == true) currentString->chr++;
  return result;
}

bool isEqualX(string* currentString) { return *(currentString->chr) == 'x'; }

bool isConstant(string* currentString, element* currentElement) {
  bool result = false;
  for (int i = 0; i < constantsCount; i++) {
    if (isSameString(currentString->chr, constantList[i].name,
                     constantList[i].nameLen)) {
      result = true;
      currentElement->num = constantList[i].value;
      currentString->chr += constantList[i].nameLen;
      break;
    }
  }
  return result;
}
