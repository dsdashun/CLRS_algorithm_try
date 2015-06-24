#ifndef _SET_ELEMENT_H
#define _SET_ELEMENT_H
typedef struct {
    union {
        int intKey;
        double doubleKey;
        char *stringKey;
    } key;
    void *pHandle;
} SetElem_t;

SetElem_t *generateElemArrayByKeyList_Double(double *pKeyList, int num);

extern SetElem_t errorElem;

#endif
