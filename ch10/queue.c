#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue_t *pQueue, int length){
    pQueue->pData = calloc(length, sizeof(SetElem_t));
    pQueue->length = length;
    pQueue->head = -1;
    pQueue->tail = 0;
}

void enqueue(Queue_t *pQueue, SetElem_t *pElem){
    if (pQueue->tail == pQueue->head){
        fprintf(stderr, "Queue is full");
        return;
    }
    memcpy(pQueue->pData + pQueue->tail, pElem, sizeof(SetElem_t));
    if (pQueue->head == -1){
        pQueue->head = pQueue->tail;
    }
    pQueue->tail = (pQueue->tail + 1) % pQueue->length;
}

SetElem_t dequeue(Queue_t *pQueue){
    SetElem_t resultElem;
    if (pQueue->head == -1){
        fprintf(stderr, "Queue is empty");
        return;
    }
    memcpy(&resultElem, pQueue->pData + pQueue->head, sizeof(SetElem_t));
    if ((pQueue->head + 1) % pQueue->length == pQueue->tail){
        pQueue->head = -1;
    }
    else {
        pQueue->head = (pQueue->head + 1) % pQueue->length;
    }
    return resultElem;
}

void dumpQueue(Queue_t *pQueue){
    int i;
    printf("Queue head: %d, tail: %d, ", pQueue->head, pQueue->tail);
    if (pQueue->head == -1){
        printf("[Empty Queue]\n");
        return;
    }
    i = pQueue->head;
    printf("[ ");
    do {
        printf("%f, ", pQueue->pData[i].key.doubleKey);
        i = (i + 1) % pQueue->length;
    } while(i != pQueue->tail);
    printf(" ]\n");
}
