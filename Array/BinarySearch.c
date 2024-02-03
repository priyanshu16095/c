#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size-1;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}
int main() {
    int arr[] = {7, 8, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 2;
    int index = binarySearch(arr, size, target);
    printf("%d", index);
}
