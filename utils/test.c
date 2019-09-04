#include "my_io_utils.h"

int* buffers[BF_SIZE] = {NULL};
int sizes[BF_SIZE] = {0};
int types[BF_SIZE] = {0};

int main() {
    sizes[0] = 100;
    sizes[1] = 80;
    types[0] = 0;
    types[1] = 1;
    
    genData(buffers, sizes, types, 2);
    showBuffers(buffers, sizes, 2);
    freeBuffers(buffers);
    return 0;
}

