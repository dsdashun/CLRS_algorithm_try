#ifndef _HEAP_H
#define _HEAP_H

#define LEFT_CHILD(i) 2 * (i) + 1
#define RIGHT_CHILD(i) 2 * (i) + 2
#define PARENT(i) ((i) - 1) / 2

typedef struct {
    double key;
    void *pHandle;
} HeapElem_t;

typedef struct {
    //double *pData;
    HeapElem_t *pData;
    int heapSize;
    int length;
} Heap_t;

int isValidIndex(Heap_t *pHeap, int index);
int nonLeafNodeNum(Heap_t *pHeap);
void dumpHeap(Heap_t *pHeap);
HeapElem_t *generateHeapDataByKeyList(double *pKeyList, int num);

extern HeapElem_t errorElem;
#endif
