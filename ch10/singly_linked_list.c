#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singly_linked_list.h"

void singlyLinkedList_insert(SinglyLinkedList_t *pList, SetElem_t *pElem) {
    SinglyLinkedListElem_t *pListElem;
    pListElem = calloc(1, sizeof(SinglyLinkedListElem_t));    //it will init the pointer data to all 0x00
    memcpy(&(pListElem->data), pElem, sizeof(SetElem_t));
    pListElem->next = (*pList);
    *pList = pListElem;
}

void singlyLinkedList_dump(SinglyLinkedList_t aLinkedList){
    int i;
    SinglyLinkedListElem_t *pListElem;
    if (aLinkedList == NULL){
        printf("[ Empty List ]\n");
        return;
    }
    pListElem = aLinkedList;
    printf("[ ");
    while (pListElem != NULL){
        printf("%f, ", pListElem->data.key.doubleKey);
        pListElem = pListElem->next;
    }
    printf(" ]\n");
}

SinglyLinkedListElem_t *singlyLinkedList_search(SinglyLinkedList_t aList, double key){
    SinglyLinkedListElem_t *pListElem;
    pListElem = aList;
    while (pListElem != NULL){
        if (pListElem->data.key.doubleKey == key){
            break;
        }
        pListElem = pListElem->next;
    }
    return pListElem;
}

void singlyLinkedList_delete(SinglyLinkedList_t *pList, SinglyLinkedListElem_t *pListElem){
    SinglyLinkedListElem_t *pPrevListElem;
    if (!pList || !pListElem){
        return;
    }
    if (pListElem == (*pList)){
        *pList = pListElem->next;
        return;
    }
    pPrevListElem = *pList;
    while (pPrevListElem != NULL){
        if (pPrevListElem->next == pListElem){
            break;
        }
    }
    if (pPrevListElem){
        pPrevListElem->next = pListElem->next;
    }
}

void singlyLinkedList_reverse(SinglyLinkedList_t *pList){
    SinglyLinkedListElem_t *pCurrent, *pPrev = NULL, *pNext;
    pCurrent = (*pList);
    while (pCurrent != NULL){
        pNext = pCurrent->next;
        pCurrent->next = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    *pList = pPrev;
}
