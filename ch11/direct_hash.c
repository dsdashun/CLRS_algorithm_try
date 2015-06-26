#include <stdio.h>
#include <stdlib.h>
#include "direct_hash.h"

Hash_t initHash(int size){
    Hash_t aHash;
    aHash.pData = calloc(size, sizeof(DoubleLinkedList_t));
    aHash.length = size;
    return aHash;
}

void dirHash_insert(Hash_t aHash, SetElem_t *pElem){
    int key = pElem->key.intKey;
    if (key >= aHash.length){
        fprintf(stderr, "key overflow\n");
        return;
    }
    if (aHash.pData[key] == NULL){
        aHash.pData[key] = initDoubleLinkedList();
    }
    doubleLinkedList_insert(aHash.pData[key], pElem);
}

DoubleLinkedList_t dirHash_search(Hash_t aHash, int key){
    if (key >= aHash.length){
        fprintf(stderr, "key overflow\n");
        return NULL;
    }
    return aHash.pData[key];
}

void dirHash_delete(Hash_t aHash, struct DoubleLinkedListElem *pListElem){
    int key = pListElem->pData->key.intKey;
    doubleLinkedList_delete(aHash.pData[key], pListElem);
    if (doubleLinkedList_isEmpty(aHash.pData[key])){
        free(aHash.pData[key]);
        aHash.pData[key] = NULL;
    }
}

int main(int argc, char *argv[]){
    Hash_t aHash;
    SetElem_t *pElem;
    DoubleLinkedList_t aLinkedList;
    struct DoubleLinkedListElem *pListElem;
    aHash = initHash(16);
    pElem = calloc(1, sizeof(SetElem_t));
    pElem->key.intKey = 3;
    dirHash_insert(aHash, pElem);
    pElem = calloc(1, sizeof(SetElem_t));
    pElem->key.intKey = 8;
    dirHash_insert(aHash, pElem);
    aLinkedList = dirHash_search(aHash, 5);
    printf("%x\n", aLinkedList);
    if (aLinkedList){
        dumpDoubleLinkedList_int(aLinkedList);
    }
    aLinkedList = dirHash_search(aHash, 3);
    printf("%x\n", aLinkedList);
    if (aLinkedList){
        dumpDoubleLinkedList_int(aLinkedList);
    }
    pElem = calloc(1, sizeof(SetElem_t));
    pElem->key.intKey = 3;
    dirHash_insert(aHash, pElem);
    aLinkedList = dirHash_search(aHash, 3);
    printf("%x\n", aLinkedList);
    if (aLinkedList){
        dumpDoubleLinkedList_int(aLinkedList);
    }
    pListElem = aLinkedList->next;
    dirHash_delete(aHash, pListElem);
    aLinkedList = dirHash_search(aHash, 3);
    printf("%x\n", aLinkedList);
    if (aLinkedList){
        dumpDoubleLinkedList_int(aLinkedList);
    }
    aLinkedList = dirHash_search(aHash, 8);
    printf("%x\n", aLinkedList);
    if (aLinkedList){
        dumpDoubleLinkedList_int(aLinkedList);
    }
    pListElem = aLinkedList->next;
    dirHash_delete(aHash, pListElem);
    aLinkedList = dirHash_search(aHash, 8);
    printf("%x\n", aLinkedList);
    if (aLinkedList){
        dumpDoubleLinkedList_int(aLinkedList);
    }
}
