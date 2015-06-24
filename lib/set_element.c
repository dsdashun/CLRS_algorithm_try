#include <float.h>
#include <stdlib.h>
#include "include/set_element.h"

SetElem_t errorElem = {.key = {.doubleKey = -DBL_MAX}, .pHandle = NULL};

SetElem_t *generateElemArrayByKeyList_Double(double *pKeyList, int num){
    int i;
    SetElem_t *pElemArray = calloc(num, sizeof(SetElem_t));
    for (i=0; i<num; i++){
        pElemArray[i].key.doubleKey = pKeyList[i];
        pElemArray[i].pHandle = NULL;
    }
    return pElemArray;
}


