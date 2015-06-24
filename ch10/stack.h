#ifndef _STACK_H
#define _STACK_H

#include "include/set_element.h"

typedef struct {
    SetElem_t *pData;
    int top;
    int length;
} Stack_t;

void initStack(Stack_t *pStack, int length);
void push(Stack_t *pStack, SetElem_t *pElem);
SetElem_t pop(Stack_t *pStack);
void dumpStack(Stack_t *pStack);

#endif
