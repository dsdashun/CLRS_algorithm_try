#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

static void BTSubTree_dump(BTNode_t *pNode, char *prefix);

void binaryTree_dump(BinaryTree_t aBinTree){
    BTSubTree_dump(aBinTree, "");
}

void BTSubTree_dump(BTNode_t *pNode, char *prefix){
    char newPrefix[128];
    if (!pNode){
        return;
    }
    printf("%s%f\n", prefix, pNode->data.key.doubleKey);
    strcpy(newPrefix, prefix);
    strcat(newPrefix, "L: \t");
    BTSubTree_dump(pNode->leftChild, newPrefix);
    strcpy(newPrefix, prefix);
    strcat(newPrefix, "R: \t");
    BTSubTree_dump(pNode->rightChild, newPrefix);
}
