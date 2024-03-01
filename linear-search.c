#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {7, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    int index = linearSearch(arr, size, target);
    printf("%d", index);
}
