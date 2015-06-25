#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

#include "include/set_element.h"

typedef struct SinglyLinkedListElem {
    SetElem_t data;
    struct SinglyLinkedListElem *next;
} SinglyLinkedListElem_t, *SinglyLinkedList_t;

void singlyLinkedList_insert(SinglyLinkedList_t *pList, SetElem_t *pElem);
SinglyLinkedListElem_t *singlyLinkedList_search(SinglyLinkedList_t aList, double key);
void singlyLinkedList_delete(SinglyLinkedList_t *pList, SinglyLinkedListElem_t *pListElem);
void singlyLinkedList_dump(SinglyLinkedList_t aLinkedList);
void singlyLinkedList_reverse(SinglyLinkedList_t *pList);
#endif
