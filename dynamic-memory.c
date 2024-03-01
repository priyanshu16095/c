#include <stdio.h>
#include <stdlib.h>

int main() {
    // The key difference between calloc and malloc is that calloc allocates the contigous memory 
    // and intializes the allocated memory to zero.
    
    int* arrCalloc = (int*)calloc(5, sizeof(int));
    int* arrMalloc = (int*)malloc(3 * sizeof(int));
    
    arrMalloc = (int*)realloc(5 * sizeof(int));
    
    free(arrCalloc);
    free(arrMalloc);
}
