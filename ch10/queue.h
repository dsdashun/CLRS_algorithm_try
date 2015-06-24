#ifndef _QUEUE_H
#define _QUEUE_H

#include "include/set_element.h"

typedef struct {
    SetElem_t *pData;
    int head;
    int tail;
    int length;
} Queue_t;

void initQueue(Queue_t *pQueue, int length);
void enqueue(Queue_t *pQueue, SetElem_t *pElem);
SetElem_t dequeue(Queue_t *pQueue);
void dumpQueue(Queue_t *pQueue);

#endif
