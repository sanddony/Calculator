#include "calculator.h"

void setEmptyElement(element* elem) {
  elem->num = 0;
  elem->operator= NULL;
}

element popStack(stack* stck, status* resCode) {
  *resCode = ERROR;
  element elem;
  if (stck) {
    *resCode = STACK_EMPTY;
    if (!isStackEmpty(stck)) {
      elem = *(stck->top);
      setEmptyElement(stck->top);
      stck->top--;
      *resCode = OK;
    }
  }
  return elem;
}

status pushStack(stack* stck, element elem) {
  status resCode = ERROR;
  if (stck) {
    resCode = STACK_FULL;
    if (!isStackFull(stck)) {
      stck->top++;
      *(stck->top) = elem;
      resCode = OK;
    }
  }
  return resCode;
}

status createStack(stackType type, stack* stck) {
  status resCode = ERROR;
  if (stck) {
    stck->type = type;
    stck->data = malloc(STACK_SIZE * sizeof(element));
    stck->top = stck->data - 1;
    resCode = STACK_CREATED;
  }
  return resCode;
}

status removeStack(stack* stck) {
  status resCode = ERROR;
  if (stck) {
    free(stck->data);
    stck->data = NULL;
    stck->top = NULL;
    resCode = OK;
  }
  return resCode;
}
