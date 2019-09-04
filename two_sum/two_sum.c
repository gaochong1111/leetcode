#include "my_io_utils.h"


int* buffers[BF_SIZE] = {NULL};
int sizes[BF_SIZE] = {0};
int types[BF_SIZE] = {0};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *       1. what should be allocated by myself???
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = NULL; 
    // returnSize = (int*) malloc(sizeof(int));
    *returnSize = 0;
    for (int idxFirst = 0; idxFirst < numsSize; idxFirst++) {
        for (int idxSecond = idxFirst + 1; idxSecond < numsSize; idxSecond++) {
            if (nums[idxFirst] + nums[idxSecond] == target) {
                result = (int*) malloc(sizeof(int) * 2);
                result[0] = idxFirst;
                result[1] = idxSecond;
                *returnSize = 2;
                break;
            }
        } 
    }
    return result;
}

#define DATA_SIZE 8

int main() {
    sizes[0] = 100;
    sizes[1] = 80;
    types[0] = 0;
    types[1] = 1;
    
    genData(buffers, sizes, types, 2);
    showBuffers(buffers, sizes, 2);

    int nums[DATA_SIZE] = {2, 7, 11, 15};
    int target = 100;
    int returnSize = 0;

    memcpy(nums, buffers[0], sizeof(int) * DATA_SIZE);

    int* result = twoSum(nums, DATA_SIZE, target, &returnSize);

    if (result != NULL) {
        printf("result: \n");
        showBuffer(result, 2);
    } else {
        printf("NO RESULT!\n");
    }

    if (result != NULL) free(result);

    freeBuffers(buffers);
    return 0;
}
