#include <stdio.h>
#include <stdlib.h>
#include <float.h>

char bitmap[4];    //4 * 8 = 32 elements

void hash_insert(int key){
    int bitmapIndex = key / 8;
    int shiftBit = key % 8;
    bitmap[bitmapIndex] |= (0x01 << shiftBit);
}

int hash_search(int key){
    int bitmapIndex = key / 8;
    int shiftBit = key % 8;
    if (bitmap[bitmapIndex] & (0x01 << shiftBit)){
        return 1;
    }
    else {
        return 0;
    }
}

void hash_delete(int key){
    int bitmapIndex = key / 8;
    int shiftBit = key % 8;
    bitmap[bitmapIndex] &= (~(0x01 << shiftBit));
}

int main(int argc, char *argv[]){
    int value;
    int index;
    hash_insert(3);
    hash_insert(17);
    hash_insert(29);
    hash_insert(15);
    index = 3;
    value = hash_search(index);
    printf("Index %d: %d\n", index, value);
    index = 14;
    value = hash_search(index);
    printf("Index %d: %d\n", index, value);
    index = 15;
    value = hash_search(index);
    printf("Index %d: %d\n", index, value);
    hash_delete(15);
    index = 15;
    value = hash_search(index);
    printf("Index %d: %d\n", index, value);
}
