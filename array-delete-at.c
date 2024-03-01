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

void deleteAt(int** arr, int* size, int index) {
    for(int i = index; i < *size; i++) {
        (*arr)[i] = (*arr)[i+1];
    }
    (*size)--;
    *arr = (int*)realloc(*arr, *size * sizeof(int));
}

int main() {
    int size = 5;
    int* arr = createArray(size);
    printArray(arr, size);
    
    deleteAt(&arr, &size, 1);
    printArray(arr, size);
}
