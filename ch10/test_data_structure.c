#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "double_linked_list.h"
#include "singly_linked_list.h"
#include "binary_tree.h"

void testStack(){
    Stack_t aStack;
    SetElem_t anElement;
    initStack(&aStack, 6);
    anElement.key.doubleKey = 4;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 1;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 3;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement = pop(&aStack);
    printf("%f\n", anElement.key.doubleKey);
    dumpStack(&aStack);
    anElement.key.doubleKey = 8;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement = pop(&aStack);
    printf("%f\n", anElement.key.doubleKey);
    dumpStack(&aStack);
    anElement.key.doubleKey = 1;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 2;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 3;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 4;
    push(&aStack, &anElement);
    dumpStack(&aStack);
    anElement.key.doubleKey = 5;
    push(&aStack, &anElement);
    dumpStack(&aStack);
}

void testQueue(){
    Queue_t aQueue;
    SetElem_t anElement;
    initQueue(&aQueue, 6);
    anElement.key.doubleKey = 4;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 1;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 3;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    printf("%f\n", anElement.key.doubleKey);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 8;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    printf("%f\n", anElement.key.doubleKey);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 1;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 2;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 3;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 4;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement.key.doubleKey = 5;
    enqueue(&aQueue, &anElement);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    anElement = dequeue(&aQueue);
    dumpQueue(&aQueue);
    anElement = dequeue(&aQueue);
    dumpQueue(&aQueue);
}

void testDoubleLinkedList(){
    SetElem_t *pElem;
    double key;
    DoubleLinkedList_t aLinkedList;
    struct DoubleLinkedListElem *pLinkElem;
    aLinkedList = initDoubleLinkedList();
    dumpDoubleLinkedList_double(aLinkedList);
    pElem = calloc(1, sizeof(SetElem_t));
    pElem->key.doubleKey = 1;
    doubleLinkedList_insert(aLinkedList, pElem);
    dumpDoubleLinkedList_double(aLinkedList);
    pElem = calloc(1, sizeof(SetElem_t));
    pElem->key.doubleKey = 2;
    doubleLinkedList_insert(aLinkedList, pElem);
    dumpDoubleLinkedList_double(aLinkedList);
    pElem = calloc(1, sizeof(SetElem_t));
    pElem->key.doubleKey = 4;
    doubleLinkedList_insert(aLinkedList, pElem);
    dumpDoubleLinkedList_double(aLinkedList);
    pLinkElem = doubleLinkedList_search(aLinkedList, 3);
    printf("0x%x\n", pLinkElem);
    pLinkElem = doubleLinkedList_search(aLinkedList, 2);
    printf("0x%x\n", pLinkElem);
    doubleLinkedList_delete(aLinkedList, pLinkElem);
    free(pLinkElem);
    dumpDoubleLinkedList_double(aLinkedList);
}

void testSinglyLinkedList(){
    SetElem_t anElement;
    double key;
    SinglyLinkedList_t aLinkedList = NULL;
    SinglyLinkedListElem_t *pListElem;
    anElement.key.doubleKey = 1;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    anElement.key.doubleKey = 2;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    anElement.key.doubleKey = 4;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    pListElem = singlyLinkedList_search(aLinkedList, 3);
    printf("0x%x\n", pListElem);
    pListElem = singlyLinkedList_search(aLinkedList, 2);
    printf("0x%x\n", pListElem);
    singlyLinkedList_delete(&aLinkedList, pListElem);
    singlyLinkedList_dump(aLinkedList);
    pListElem = singlyLinkedList_search(aLinkedList, 4);
    singlyLinkedList_delete(&aLinkedList, pListElem);
    singlyLinkedList_dump(aLinkedList);
    anElement.key.doubleKey = 2;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    anElement.key.doubleKey = 3;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    anElement.key.doubleKey = 4;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    anElement.key.doubleKey = 5;
    singlyLinkedList_insert(&aLinkedList, &anElement);
    singlyLinkedList_dump(aLinkedList);
    singlyLinkedList_reverse(&aLinkedList);
    singlyLinkedList_dump(aLinkedList);
}

void testBinaryTree(){
    BinaryTree_t aTree;
    BTNode_t *pNode, *pParentNode;
    aTree = calloc(1, sizeof(BTNode_t));
    pParentNode = aTree;
    pNode = calloc(1, sizeof(BTNode_t));
    pNode->data.key.doubleKey = 1;
    pNode->parent = pParentNode;
    pParentNode->leftChild = pNode;
    pNode = calloc(1, sizeof(BTNode_t));
    pNode->data.key.doubleKey = 2;
    pNode->parent = pParentNode;
    pParentNode->rightChild = pNode;
    pParentNode = pNode->parent->leftChild;
    pNode = calloc(1, sizeof(BTNode_t));
    pNode->data.key.doubleKey = 3;
    pNode->parent = pParentNode;
    pParentNode->rightChild = pNode;
    pParentNode = pParentNode->parent->rightChild;
    pNode = calloc(1, sizeof(BTNode_t));
    pNode->data.key.doubleKey = 4;
    pNode->parent = pParentNode;
    pParentNode->leftChild = pNode;
    binaryTree_dump(aTree);
}

int main(int argc, char *argv[]){
    //testStack();
    //testQueue();
    testDoubleLinkedList();
    //testSinglyLinkedList();
    //testBinaryTree();
}
