#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "double_linked_list.h"

DoubleLinkedList_t initDoubleLinkedList(){
    DoubleLinkedList_t resultLinkedList;
    resultLinkedList = malloc(sizeof(struct DoubleLinkedListElem));
    resultLinkedList->next = resultLinkedList;
    resultLinkedList->prev = resultLinkedList;
    resultLinkedList->pData = NULL;
    return resultLinkedList;
}

void doubleLinkedList_insert(DoubleLinkedList_t aLinkedList, SetElem_t *pElem){
    struct DoubleLinkedListElem *pNewElem;
    pNewElem = malloc(sizeof(struct DoubleLinkedListElem));
    pNewElem->pData = pElem;
    pNewElem->next = aLinkedList->next;
    aLinkedList->next->prev = pNewElem;
    pNewElem->prev = aLinkedList;
    aLinkedList->next = pNewElem;
}

void doubleLinkedList_delete(DoubleLinkedList_t aLinkedList, struct DoubleLinkedListElem *pElem){
    pElem->next->prev = pElem->prev;
    pElem->prev->next = pElem->next;
}

struct DoubleLinkedListElem *doubleLinkedList_search(DoubleLinkedList_t aLinkedList, double key){
    struct DoubleLinkedListElem *pElem;
    pElem = aLinkedList->next;
    while (pElem != aLinkedList){
        if (pElem->pData->key.doubleKey == key){
            return pElem;
        }
        pElem = pElem->next;
    }
    return NULL;
}

int doubleLinkedList_isEmpty(DoubleLinkedList_t aLinkedList){
    if (aLinkedList->next == aLinkedList){
        return 1;
    }
    else {
        return 0;
    }
}

void dumpDoubleLinkedList_double(DoubleLinkedList_t aLinkedList){
    struct DoubleLinkedListElem *pListElem;
    if (aLinkedList->next == aLinkedList){
        printf("[ Empty double linked list ]\n");
        return;
    }
    pListElem = aLinkedList->next;
    printf("[ ");
    while (pListElem != aLinkedList){
        printf("%f <=> ", pListElem->pData->key.doubleKey);
        pListElem = pListElem->next;
    }
    printf(" ]\n");
}

void dumpDoubleLinkedList_int(DoubleLinkedList_t aLinkedList){
    struct DoubleLinkedListElem *pListElem;
    if (aLinkedList->next == aLinkedList){
        printf("[ Empty double linked list ]\n");
        return;
    }
    pListElem = aLinkedList->next;
    printf("[ ");
    while (pListElem != aLinkedList){
        printf("%d <=> ", pListElem->pData->key.intKey);
        pListElem = pListElem->next;
    }
    printf(" ]\n");
}
