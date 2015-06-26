#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include "include/set_element.h"

typedef struct BTNode {
    SetElem_t data;
    struct BTNode *parent;
    struct BTNode *leftChild;
    struct BTNode *rightChild;
} BTNode_t, *BinaryTree_t;

void binaryTree_dump(BinaryTree_t aBinTree);

#endif
