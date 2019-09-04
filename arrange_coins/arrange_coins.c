#include "my_io_utils.h"
int* buffers[BF_SIZE] = {NULL};
int sizes[BF_SIZE] = {0};
int types[BF_SIZE] = {0};

int arrangeCoins(int n){
    int result = 0;
    int lineCount = 1;
    while (n >= lineCount) {
        result ++;
        n -= lineCount;
        lineCount++;
    }
    return result;
}

void testOne() {
    int n = 5;
    int result = arrangeCoins(n);
    printf("res: %d\n", result);
}

#define DATA_SIZE 5
void testBatch() {
    int inputs[] = {0, 1, 5, 8, INT_MAX};
    int outputs[DATA_SIZE];
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        outputs[idx] = arrangeCoins(inputs[idx]);
    }
    showArray(outputs, DATA_SIZE);
}

int main() {
    // main code
    testOne();
    testBatch();
    return 0;
}    
