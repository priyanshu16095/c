#include <stdio.h>
#include <stdlib.h>

int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    return arr;
}
void printArray(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// The arr here is pointer-to-pointer to ensure reallocation in the original array.
void insertAt(int** arr, int* size, int index, int element) {
    (*size)++;
    *arr = (int*)realloc(*arr, *size * sizeof(int));
    for (int i = *size-1; i > index; i--) {
        (*arr)[i] = (*arr)[i-1];
    }
    (*arr)[index] = element;
}


int main() {
    int size = 5;
    int* arr = createArray(size);
    printArray(arr, size);
    
    insertAt(&arr, &size, 2, 9);
    printArray(arr, size);
}















