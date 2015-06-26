#ifndef _DIRECT_HASH_H
#define _DIRECT_HASH_H
#include "include/set_element.h"
#include "../ch10/double_linked_list.h"

typedef struct {
    DoubleLinkedList_t *pData;
    int length;
} Hash_t;

Hash_t initHash(int size);
void dirHash_insert(Hash_t aHash, SetElem_t *pElem);
DoubleLinkedList_t dirHash_search(Hash_t aHash, int key);
void dirHash_delete(Hash_t aHash, struct DoubleLinkedListElem *pListElem);

#endif
