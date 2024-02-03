#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 1; j < size-i; j++) {
            if(arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr, size);
}
int main() {
    int arr[] = {7, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
}






