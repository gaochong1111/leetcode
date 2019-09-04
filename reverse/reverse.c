#include "my_io_utils.h"
int* buffers[BF_SIZE] = {NULL};
int sizes[BF_SIZE] = {0};
int types[BF_SIZE] = {0};

// 1. valid check (overflow)
int reverse(int x) {
    long result = 0;
    int factor = 10;
    int sign = 1;
    if (x < 0) sign = -1;

    while (x != 0) {
        result = result * factor + sign * (x % 10);
        x /= 10;
    }
    result = sign * result;

    if (result > INT_MAX || result < INT_MIN)
        return 0;
    return result;
}

void testBits() {
    int y = -2147483648;
    printf("y: %d\n", y);
    long x = 0 - (long)y ;
    printf("x: %ld\n", x);
    while (x != 0) {
        printf("bit: %ld\t", x%10);
        x /= 10;
    }
    printf("\n");
}


#define DATA_SIZE 8

int main() {
    // test code
    printf("MIN: %d, MAX: %d\n", INT_MAX, INT_MIN);
    // main code
    int inputs[] = {123, -123, 120, 0, 1, -1, INT_MAX, INT_MIN};
    int output[DATA_SIZE] = {0};
    // int result = reversePlus(input);
    for (int idx = 0; idx < DATA_SIZE; idx++) {
        output[idx] = reverse(inputs[idx]);
    }
    showArray(output, DATA_SIZE);
    return 0;
}        
