#include <stdio.h>
#include "stack.h"
#include "queue.h"

void testStack(){
    Stack_t aStack;
    SetElem_t anElement;
    initStack(&aStack, 6);
    anElement.key.doubleKey = 4;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 1;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 3;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement = pop(&aStack);
    printf("%f\n", anElement.key.doubleKey);
    dumpStack(&aStack);
    anElement.key.doubleKey = 8;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement = pop(&aStack);
    printf("%f\n", anElement.key.doubleKey);
    dumpStack(&aStack);
    anElement.key.doubleKey = 1;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 2;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 3;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 4;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 5;
    push(&aStack, &anElement);
    dumpStack(&aStack);
}

void testQueue(){
    Queue_t aQueue;
    SetElem_t anElement;
    initQueue(&aQueue, 6);
    anElement.key.doubleKey = 4;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 1;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 3;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    printf("%f\n", anElement.key.doubleKey);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 8;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    printf("%f\n", anElement.key.doubleKey);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 1;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 2;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 3;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 4;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 5;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    dumpQueue(&aQueue);
}

int main(int argc, char *argv[]){
    testStack();
    testQueue();
}
