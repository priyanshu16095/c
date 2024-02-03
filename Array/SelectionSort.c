#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int smallest = i; //INDEX
        for(int j = i+1; j < size; j++) {
            if(arr[smallest] > arr[j]) {
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
    printArray(arr, size);
}
int main() {
    int arr[] = {7, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
}
