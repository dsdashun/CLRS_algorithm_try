#ifndef _DOUBLE_LINKED_LIST
#define _DOUBLE_LINKED_LIST

#include "include/set_element.h"

typedef struct DoubleLinkedListElem {
    struct DoubleLinkedListElem *prev;
    SetElem_t data;
    struct DoubleLinkedListElem *next;
} *DoubleLinkedList_t;

DoubleLinkedList_t initDoubleLinkedList();
void doubleLinkedList_insert(DoubleLinkedList_t aLinkedList, SetElem_t *pElem);
void doubleLinkedList_delete(DoubleLinkedList_t aLinkedList, struct DoubleLinkedListElem *pElem);
struct DoubleLinkedListElem *doubleLinkedList_search(DoubleLinkedList_t aLinkedList, double key);
void dumpDoubleLinkedList(DoubleLinkedList_t aLinkedList);

#endif
