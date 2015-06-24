#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void initStack(Stack_t *pStack, int length){
    pStack->pData = calloc(length, sizeof(SetElem_t));
    pStack->length = length;
    pStack->top = 0;
}

void push(Stack_t *pStack, SetElem_t *pElem){
    if (pStack->top >= pStack->length){
        fprintf(stderr, "Stack overflow\n");
        return;
    }
    memcpy(pStack->pData + pStack->top, pElem, sizeof(SetElem_t));
    (pStack->top)++;
}

SetElem_t pop(Stack_t *pStack){
    SetElem_t resultElem;
    if (pStack->top == 0){
        fprintf(stderr, "Stack underflow\n");
        return;
    }
    (pStack->top)--;
    memcpy(&resultElem, pStack->pData + pStack->top, sizeof(SetElem_t));
    return resultElem;
}

void dumpStack(Stack_t *pStack){
    int i;
    if (pStack->top == 0){
        printf("[ Empty Stack ]\n");
        return;
    }
    printf("[ ");
    for (i=0; i<pStack->top; i++){
        printf("%f, ", pStack->pData[i].key.doubleKey);
    }
    printf(" ]\n");
}
