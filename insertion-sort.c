#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int current = arr[i];   // SORTED PART OF ARRAY
        int j = i-1;          //INDEX OF SORTED ELEMENT
        while(j >= 0 && current < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    printArray(arr, size);
}

int main() {
    int arr[] = {7, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
}
