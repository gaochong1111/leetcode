#ifndef MY_IO_UTILS_H
#define MY_IO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BF_SIZE 8
#define MAX_NUM 100
#define NUM_OF_LINE 8




void genRandomData(int* buffer, int dataSize) {
    // seed
    srand(time(NULL));
    for (int counter = 0; counter < dataSize; counter++) {
        buffer[counter] = rand() % MAX_NUM;
    }
}

int exists(int* data, int size, int target) {
    for (int idx = 0; idx < size; idx++) {
        if (data[idx] == target)
            return 1;
    }
    return 0;
}

void genNoDupRandomData(int* buffer, int dataSize) {
    // seed
    srand(time(NULL));
    for (int counter = 0; counter < dataSize; counter++) {
        int candidate =  rand() % MAX_NUM;
        if (!exists(buffer, counter, candidate)) {
            buffer[counter] = candidate;        
        } else {
            // printf("dup!!!\n");
            counter--;
        }
    }
}


void genData(int** buffers, int* sizes, int* types, int validSize) {
    for (int idx = 0; idx < validSize; idx++) {
        buffers[idx] = (int*) malloc(sizes[idx] * sizeof(int));
        if (types[idx] == 0) {
            genRandomData(buffers[idx], sizes[idx]);
        } else {
            genNoDupRandomData(buffers[idx], sizes[idx]);
        }
    }
}

void showBuffer(int* buffer, int dataSize) {
    for (int counter = 0; counter < dataSize; counter++) {
        printf("%d ", buffer[counter]);
        if ((counter + 1) % NUM_OF_LINE == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void showBuffers(int** buffers, int* sizes, int validSize) {
    printf("Buffers:\n");
    for (int idx = 0; idx < validSize; idx++) {
        printf("Buffer::%d\n", idx);
        showBuffer(buffers[idx], sizes[idx]);
    }
    printf("\n");
}

void freeBuffers(int** buffers) {
    for (int idx = 0; idx < BF_SIZE; idx++) {
        if (buffers[idx] != NULL) { 
            free(buffers[idx]);
        }
    }
}

#endif

